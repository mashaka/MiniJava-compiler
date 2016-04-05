#include "StmList.hpp"
#include "LabelObj.hpp"

#include "StmListList.hpp"
#include "BasicBlocks.hpp"

#include "LABEL.hpp"
#include "JUMP.hpp"
#include "CJUMP.hpp"

#include <memory>
#include <unordered_map>

namespace Canon {
	class TraceSchedule {
	public:
		std::shared_ptr<Tree::StmList> stms;
		std::shared_ptr<TBasicBlocks> theBlocks;
		std::unordered_map<std::shared_ptr<Tree::Label>, std::shared_ptr<Tree::StmList>> table;

		TraceSchedule(std::shared_ptr<BasicBlocks> _theBlocks):
		theBlocks(_theBlocks)
		{
			table = new std::unordered_map<std::shared_ptr<Tree::Label>, std::shared_ptr<Tree::StmList>>();
			for (std::shared_ptr<StmListList> l = b->blocks; l != nullptr; l = l->tail) {
				table[l->head->head->label] = l->head;
			}
			stms = getNext();
			table = nullptr;
		}

		std::shared_ptr<Tree::StmList> getLast(std::shared_ptr<Tree::StmList> block) {
			std::shared_ptr<Tree::StmList> l = block;
			while (l->tail->tail != nullptr) l = l->tail;
			return l;
		}

		void trace(std::shared_ptr<Tree::StmList> l) {
			while (true) {
				std::shared_ptr<Tree::Label> lab = l->head;
				table.remove(lab->label);
				std::shared_ptr<Tree::StmList> last = getLast(l);
				std::shared_ptr<Tree::Stm> s = last->tail->head;
				if (dynamic_cast<Tree::JUMP>(*s) != nullptr) {
					std::shared_ptr<Tree::JUMP> j = s;
					std::shared_ptr<Tree::StmList> target = table[j->targets->head];
					if (j->targets->tail == nullptr && target != nullptr) {
						last->tail = target;
						l = target;
					} else {
						last->tail->tail=getNext();
						return;
					}
				} else if (dynamic_cast<Tree::CJUMP>(*s) != nullptr) {
					std::shared_ptr<Tree::CJUMP> j = s;
					std::shared_ptr<Tree::StmList> t = table.get[j->iftrue];
					std::shared_ptr<Tree::StmList> f = table.get[j->iffalse];
					if (f != nullptr) {
						last->tail->tail = f;
						l = f;
					} else if (t != nullptr) {
						last->tail->head = new Tree::CJUMP(Tree::CJUMP.notRel(j->relop), j->left, j->right, j->iffalse, j->iftrue);
						last->tail->tail = t;
						l = t;
					} else {
						std::shared_ptr<Temp::Label> ff = new Temp::Label();
						last->tail->head = new Tree::CJUMP(j->relop, j->left, j->right, j->iftrue, ff);
						last->tail->tail = new Tree::StmList(new Tree::LABEL(ff), new Tree::StmList(new Tree::JUMP(j->iffalse), getNext()));
						return;
					}
				} else {
					throw "Bad basic block in TraceSchedule";
				}
			}
		}

		std::shared_ptr<Tree::StmList> getNext() {
			if (theBlocks->blocks == nullptr) {
				return new Tree::StmList(new Tree::LABEL(theBlocks->done), nullptr);
			} else {
				std::shared_ptr<Tree::StmList> s = theBlocks->blocks->head;
				std::shared_ptr<Tree::LABEL> lab = s->head;
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
