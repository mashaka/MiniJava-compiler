#pragma once

#include "ExpInterface.hpp"
#include "ExpList.hpp"
#include "Print.hpp"

#include <memory>

namespace Tree {
	class Print;

	class CONST : public Exp {
	public:
		int value;

		CONST(int _value) : value(_value) {}

		std::shared_ptr<ExpList> kids() {
			return nullptr;
		}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> kids) {
			return std::dynamic_pointer_cast<Exp>(std::make_shared<CONST>(*this));
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("CONST "); 
			Print::say(std::to_string(this->value));
		}
	};
}