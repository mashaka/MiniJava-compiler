#pragma once

#include "StmList.hpp"
#include "StmListList.hpp"
#include "LabelObj.hpp"
#include "JUMP.hpp"
#include "CJUMP.hpp"
#include "LABEL.hpp"

namespace Canon {
	class BasicBlock {
	public:
		std::shared_ptr<StmListList> blocks;
		std::shared_ptr<Temp::Label> done;

		BasicBlock(std::shared_ptr<Tree::StmList> _stms) {
			done = std::make_shared<Temp::Label>();
			mkBlocks(_stms);
		}

	private:
		std::shared_ptr<StmListList> lastBlock;
		std::shared_ptr<Tree::StmList> lastStm;

		void addStm(std::shared_ptr<Tree::Stm> _stm) {
			lastStm->tail = std::make_shared<Tree::StmList>(_stm, nullptr);
			lastStm = lastStm->tail;
		}

		void doStms(std::shared_ptr<Tree::StmList> _list) {
			if (_list == nullptr) {
				doStms(std::make_shared<Tree::StmList>(std::make_shared<Tree::JUMP>(done), nullptr));
			} else if (std::dynamic_pointer_cast<Tree::JUMP>(_list->head) || std::dynamic_pointer_cast<Tree::CJUMP>(_list->head)) {
				addStm(_list->head);
				mkBlocks(_list->tail);
			} else if(std::shared_ptr<Tree::LABEL> label = std::dynamic_pointer_cast<Tree::LABEL>(_list->head)) {
				doStms(std::make_shared<Tree::StmList>(std::make_shared<Tree::JUMP>(label->label, _list)));
			} else {
				addStm(_list->head);
				doStms(_list->tail);
			}
		}

		void mkBlocks(std::shared_ptr<Tree::StmList> _list) {
			if (_list == nullptr) {
				return;
			} else if (std::dynamic_pointer_cast<Tree::LABEL>(_list->head)) {
				lastStm = std::make_shared<Tree::StmList>(_list->head, nullptr);
				if (lastBlock == nullptr) {
					blocks = std::make_shared<StmListList>(lastStm, nullptr);
					lastBlock = blocks;
				} else {
					lastBlock->tail = std::make_shared<StmListList>(lastStm, nullptr);
					lastBlock = lastBlock->tail;
				}
				doStms(_list->tail);
			} else {
				mkBlocks(std::make_shared<Tree::StmList>(std::make_shared<Tree::LABEL>(Temp::Label(), _list));
			}
		}
	};
}