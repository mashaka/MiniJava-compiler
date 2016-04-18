#pragma once

#include "TempMap.hpp"
#include "TempObj.hpp"
#include <string>

namespace Temp {
	class DefaultMap: public TempMap {
	public:
		DefaultMap() {}
		
		std::string tempMap(std::shared_ptr<Temp> t) {
			return t->toString();
		}
	};
}