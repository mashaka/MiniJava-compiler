#pragma once

#include "ExpInterface.hpp"
#include "ExpList.hpp"

#include <memory>

namespace Tree {
	class CONST : public Exp {
	public:
		int value;

		CONST(int _value) : value(_value) {}

		std::shared_ptr<ExpList> kids() {return nullptr;}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> kids) {return this;}
	};
}