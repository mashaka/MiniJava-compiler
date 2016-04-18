#pragma once

#include <memory>

#include "TempObj.hpp"
#include "StmInterface.hpp"
#include "ExpInterface.hpp"
#include "ExpList.hpp"
#include "MEM.hpp"
#include "Print.hpp"

namespace Tree {
	class Print;

	class MOVE : public Stm {
	public:
		std::shared_ptr<Exp> dst, src;

		MOVE(std::shared_ptr<Exp> _dst, std::shared_ptr<Exp> _src):
		dst(_dst), src(_src)
		{}

		std::shared_ptr<ExpList> kids() override {
			if (std::shared_ptr<MEM> newDst = std::dynamic_pointer_cast<MEM>(dst)) {
				return std::make_shared<ExpList>(newDst->exp, std::make_shared<ExpList>(src, nullptr));
			} else {
				return std::make_shared<ExpList>(src, nullptr);
			}
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
			if (std::dynamic_pointer_cast<MEM>(dst)) {
				return std::make_shared<MOVE>(_kids->head, _kids->tail->head);
			} else {
				return std::make_shared<MOVE>(dst, _kids->head);
			}
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("MOVE("); 
			this->dst->print(d + 1); 
			Print::sayln(",");
			this->src->print(d + 1); 
			Print::say(")");
		}
	};
}