#pragma once

#include "StmInterface.hpp"
#include "ExpInterface.hpp"
#include "ExpList.hpp"
#include "Print.hpp"

#include <memory>
#include <iostream>

namespace Tree {
	class ESEQ : public Exp {
	public:
		std::shared_ptr<Stm> stm;
		std::shared_ptr<Exp> exp;

		ESEQ(std::shared_ptr<Stm> _stm, std::shared_ptr<Exp> _exp)
			: stm(_stm), exp(_exp) {}

		std::shared_ptr<ExpList> kids() {
			std::cerr << "kids() not applicable to ESEQ" << std::endl;
			return nullptr;
		}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList>  kids) {
			std::cerr << "build() not applicable to ESEQ" << std::endl;
			return nullptr;
		}

		void print(ESEQ exp, int d = 0) {
			Print::indent(d); 
			Print::sayln("ESEQ("); 
			Print::print(exp.stm, d + 1); 
			Print::sayln(",");
			Print::print(exp.exp, d + 1); 
			Print::say(")");
		}
	};
}