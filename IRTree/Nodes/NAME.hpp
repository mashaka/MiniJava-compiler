#pragma once

#include "ExpList.hpp"
#include "LabelObj.hpp"
#include "ExpInterface.hpp"
#include <memory>
#include "Print.hpp"

namespace Tree {
	class NAME : public Exp {
	public:
		std::shared_ptr<Temp::Label> label;

		NAME(std::shared_ptr<Temp::Label> _label):
		label(_label)
		{}

		std::shared_ptr<ExpList> kids() {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
			return std::dynamic_pointer_cast<Exp>(std::make_shared<NAME>(*this));
		}

		void print(NAME exp, int d = 0) {
			Print::indent(d); 
			Print::say("NAME "); 
			Print::say(exp.label->toString());
		}
	};
}
