#pragma once

#include "StmList.hpp"
#include "LabelObj.hpp"

#include "StmListList.hpp"
#include "BasicBlocks.hpp"

#include "LABEL.hpp"
#include "JUMP.hpp"
#include "CJUMP.hpp"
#include "BasicBlocks.hpp"

#include <memory>
#include <unordered_map>

namespace Canon {
	class TraceSchedule {
	public:
		std::shared_ptr<Tree::StmList> stms;
		std::shared_ptr<BasicBlocks> theBlocks;
		std::unordered_map<std::shared_ptr<Temp::Label>, std::shared_ptr<Tree::StmList>> table;

		TraceSchedule(std::shared_ptr<BasicBlocks> _theBlocks):
		theBlocks(_theBlocks)
		{
			table = std::unordered_map<std::shared_ptr<Temp::Label>, std::shared_ptr<Tree::StmList>>();
			for (std::shared_ptr<StmListList> l = _theBlocks->blocks; l != nullptr; l = l->tail) {
				table[(std::dynamic_pointer_cast<Tree::LABEL>(l->head->head))->label] = l->head;
			}
			stms = getNext();
			table = std::unordered_map<std::shared_ptr<Temp::Label>, std::shared_ptr<Tree::StmList>>();
		}

		std::shared_ptr<Tree::StmList> getLast(std::shared_ptr<Tree::StmList> block) {
			std::shared_ptr<Tree::StmList> l = block;
			while (l->tail->tail != nullptr) l = l->tail;
			return l;
		}

		void trace(std::shared_ptr<Tree::StmList> l) {
			while (true) {
				std::shared_ptr<Tree::LABEL> lab = std::dynamic_pointer_cast<Tree::LABEL>(l->head);
				table.erase(lab->label);
				std::shared_ptr<Tree::StmList> last = getLast(l);
				std::shared_ptr<Tree::Stm> s = last->tail->head;
				if (std::dynamic_pointer_cast<Tree::JUMP>(s) != nullptr) {
					std::shared_ptr<Tree::JUMP> j = std::dynamic_pointer_cast<Tree::JUMP>(s);
					std::shared_ptr<Tree::StmList> target = table[j->targets->head];
					if (j->targets->tail == nullptr && target != nullptr) {
						last->tail = target;
						l = target;
					} else {
						last->tail->tail=getNext();
						return;
					}
				} else if (std::dynamic_pointer_cast<Tree::CJUMP>(s) != nullptr) {
					std::shared_ptr<Tree::CJUMP> j = std::dynamic_pointer_cast<Tree::CJUMP>(s);
					auto t_iter = table.find(j->iftrue);
					auto f_iter = table.find(j->iffalse);
					if (f_iter != table.end()) {
						std::shared_ptr<Tree::StmList> f = table[j->iffalse];
						last->tail->tail = f;
						l = f;
					} else if (t_iter != table.end()) {
						std::shared_ptr<Tree::StmList> t = table[j->iftrue];
						last->tail->head = std::make_shared<Tree::CJUMP>(Tree::CJUMP::notRel(j->relop), j->left, j->right, j->iffalse, j->iftrue);
						last->tail->tail = t;
						l = t;
					} else {
						std::shared_ptr<Tree::LABEL> ff = std::make_shared<Tree::LABEL>();
						last->tail->head = std::make_shared<Tree::CJUMP>(j->relop, j->left, j->right, j->iftrue, ff);
						last->tail->tail = std::make_shared<Tree::StmList>(std::make_shared<Tree::LABEL>(ff), std::make_shared<Tree::StmList>(std::make_shared<Tree::JUMP>(j->iffalse), getNext()));
						return;
					}
				} else {
					throw "Bad basic block in TraceSchedule";
				}
			}
		}

		std::shared_ptr<Tree::StmList> getNext() {
			if (theBlocks->blocks == nullptr) {
				return std::make_shared<Tree::StmList>(std::make_shared<Tree::LABEL>(theBlocks->done), nullptr);
			} else {
				std::shared_ptr<Tree::StmList> s = theBlocks->blocks->head;
				std::shared_ptr<Tree::LABEL> lab = std::dynamic_pointer_cast<Tree::LABEL>(s->head);
				if (table[lab->label] != nullptr) {
					trace(s);
					return s;
				} else {
					theBlocks->blocks = theBlocks->blocks->tail;
					return getNext();
				}
			}
		}

	};
}
