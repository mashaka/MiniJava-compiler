#pragma once

#include "StmInterface.hpp"
#include "ExpInterface.hpp"
#include "ExpList.hpp"

#include <memory>

namespace Tree {
	class EXP : public Stm {
		std::shared_ptr<Exp> exp; 

		EXP(std::shared_ptr<Exp> _exp) : exp(_exp) {}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(exp, nullptr);
		}
		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
  			return std::make_shared<EXP>(_kids->head);
		}
	};
}