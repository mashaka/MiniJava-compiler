#pragma once

#include "TempObj.hpp"

namespace Temp {
	// should be interface
	interface TempMap {
	public:
		TempMap(std::shared_ptr<Temp::Temp>);
	};
}
