#pragma once

#include "ExpList.hpp"
#include "LabelObj.hpp"
#include "ExpInterface.hpp"
#include <memory>
#include "Print.hpp"

namespace Tree {
	class Print;

	class NAME : public Exp {
	public:
		std::shared_ptr<Temp::Label> label;

		NAME(std::shared_ptr<Temp::Label> _label):
		label(_label)
		{}

		std::shared_ptr<ExpList> kids() override {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) override {
			return std::dynamic_pointer_cast<Exp>(std::make_shared<NAME>(*this));
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("NAME "); 
			Print::say(this->label->toString());
		}
	};
}
