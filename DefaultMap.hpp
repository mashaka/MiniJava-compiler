#include "TempMap.hpp"
#include "Temp.hpp"
#include <string>

namespace Temp {
	class DefaultMap: public Temp::TempMap {
	public:
		DefaultMap() {}
		
		std::string tempMap(Temp::Temp t) {
			return t.toString();
		}
	};
}