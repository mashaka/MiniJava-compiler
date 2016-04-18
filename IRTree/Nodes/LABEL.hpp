#pragma once

#include "TempObj.hpp"
#include "ExpList.hpp"
// Маша должна написать этот файл :)
#include "LabelObj.hpp"
// Никита должен написать этот файл :)
#include "StmInterface.hpp"
#include "Print.hpp"

#include <memory>

namespace Tree {
	class Print;

	class LABEL : public Stm {
	public:
		std::shared_ptr<Temp::Label> label;
		
		LABEL(std::shared_ptr<Temp::Label> _label):
		label(_label)
		{}

		std::shared_ptr<ExpList> kids() override {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
			return shared_from_this();
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("LABEL "); 
			Print::say(this->label->toString());
		}
	};
}