#pragma once

#include "ExpInterface.hpp"
#include "ExpList.hpp"
#include "Print.hpp"

#include <memory>

namespace Tree {
	class Print;

	class CALL : public Exp {
	public:
		std::shared_ptr<Exp> func;
		std::shared_ptr<ExpList> args;

		CALL(std::shared_ptr<Exp> _func, std::shared_ptr<ExpList> _args) 
			: func(_func), args(_args) {}

		std::shared_ptr<ExpList> kids() override {
			return std::make_shared<ExpList>(func, args);
		}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) override {
			return std::make_shared<CALL>(_kids->head, _kids->tail);
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("CALL(");
			this->func->print(d + 1);
			for(std::shared_ptr<ExpList> a = this->args; a != nullptr; a = a->tail) {
				Print::sayln(","); 
				a->head->print(d + 2); 
			}
			Print::say(")");
		}
	};
}
