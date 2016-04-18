#pragma once

#include "StmInterface.hpp"
#include "ExpInterface.hpp"
#include "ExpList.hpp"
#include "Print.hpp"

#include <memory>

namespace Tree {
	class Print;

	class EXP : public Stm {
	public:
		std::shared_ptr<Exp> exp; 

		EXP(std::shared_ptr<Exp> _exp) : exp(_exp) {}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(exp, nullptr);
		}
		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
  			return std::make_shared<EXP>(_kids->head);
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("EXP("); 
			this->exp->print(d + 1); 
			Print::say(")");
		}
	};
}