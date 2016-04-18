#pragma once

#include <memory>

#include "TempObj.hpp"
#include "ExpInterface.hpp"
#include "ExpList.hpp"
#include "Print.hpp"

namespace Tree {
	class Print;

	class MEM : public Exp {
	public:
		std::shared_ptr<Exp> exp;

		MEM(std::shared_ptr<Exp> _exp):
		exp(_exp)
		{}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(exp, nullptr);
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
			return std::make_shared<MEM>(_kids->head);
		}

		void print(int d = 0) override {
			Print::indent(d);
			Print::sayln("MEM("); 
			this->exp->print(d + 1); 
			Print::say(")");
		}
	};
}