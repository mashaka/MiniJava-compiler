#pragma once

#include "TempObj.hpp"
#include "ExpList.hpp"
#include "LabelObj.hpp"
#include "StmInterface.hpp"
#include "Print.hpp"

#include <memory>

namespace Tree {
	class Print;

	class SEQ : public Stm {
	public:
		std::shared_ptr<Stm> left, right;
		
		SEQ(std::shared_ptr<Stm> _left, std::shared_ptr<Stm> _right):
		left(_left),
		right(_right)
		{}

		std::shared_ptr<ExpList> kids() {
			throw "kids() not applicable to SEQ";
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
			throw "kids() not applicable to SEQ";
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("SEQ("); 
			this->left->print(d + 1); 
			Print::sayln(",");
			this->right->print(d + 1); 
			Print::say(")");
		}
	};
}