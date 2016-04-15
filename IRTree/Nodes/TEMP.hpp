#pragma once

#include "TempObj.hpp"
#include "ExpList.hpp"
#include "LabelObj.hpp"
#include "ExpInterface.hpp"
#include <memory>

namespace Tree {
	class TEMP : public Exp {
	public:
		std::shared_ptr<Temp::Temp> temp;

		TEMP(std::shared_ptr<Temp::Temp> _temp): temp(_temp) {}

		std::shared_ptr<ExpList> kids() {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
			return std::dynamic_pointer_cast<Exp>(std::make_shared<TEMP>(*this));
		}
	};
}