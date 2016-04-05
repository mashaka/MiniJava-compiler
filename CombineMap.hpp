#include "TempMap.hpp"
#include "TempObj.hpp"
#include <string>

namespace Temp {
	class CombineMap: public Temp::TempMap {
		Temp::TempMap tmap1, tmap2;
	public:
		CombineMap(Temp::Temp t1, Temp::Temp t2) : tmap1(t1), tmap2(t2) {}

		std::string tempMap(Temp::Temp t) {
			std::string s = tmap1.tempMap(t);
			// not sure about string comparison
			if s != "":
				return s
			return tmap2.tempMap(t);
		}
	};
}