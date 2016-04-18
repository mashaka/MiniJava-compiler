#pragma once

#include <memory>

#include "TempObj.hpp"
#include "ExpInterface.hpp"
#include "ExpList.hpp"
// Маша должна написать эти файлы :)
#include "LabelObj.hpp"
#include "LabelList.hpp"
// Никита должен написать эти файлы :)
#include "StmInterface.hpp"
#include "NAME.hpp"
#include "Print.hpp"

namespace Tree {
	class Print;

	class JUMP : public Stm {
	public:
		std::shared_ptr<Exp> exp;
		std::shared_ptr<Temp::LabelList> targets;

		JUMP(std::shared_ptr<Exp> _exp, std::shared_ptr<Temp::LabelList> _targets):
		exp(_exp), targets(_targets) 
		{}

		JUMP(std::shared_ptr<Temp::Label> _target) : JUMP(std::make_shared<NAME>(_target), std::make_shared<Temp::LabelList>(_target, nullptr))
		{}

		std::shared_ptr<ExpList> kids() override {
			return std::make_shared<ExpList>(exp, nullptr);
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
			return std::make_shared<JUMP>(_kids->head, targets);
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("JUMP("); 
			this->exp->print(d + 1); 
			Print::say(")");
		}
	};
}