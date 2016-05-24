#pragma once

#include "LabelList.hpp"

#include <memory>


namespace Assem {

class Targets {
public:
	std::shared_ptr<Temp::LabelList> labels;

	Targets(std::shared_ptr<Temp::LabelList> _labels)
		: labels(_labels) {}
};

}
