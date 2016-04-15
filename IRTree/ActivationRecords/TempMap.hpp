#pragma once

#include "TempObj.hpp"
#include <string>
#include <memory>

namespace Temp {
	// should be interface
	class TempMap {
	public:
		virtual std::string tempMap(std::shared_ptr<Temp> t) = 0;
	};
}
