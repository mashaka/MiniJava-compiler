#pragma once

#include "TempMap.hpp"
#include "TempObj.hpp"
#include <string>

namespace Temp {
	class CombineMap: public TempMap {
		std::shared_ptr<TempMap> tmap1, tmap2;
	public:
		CombineMap(std::shared_ptr<TempMap> t1, std::shared_ptr<TempMap> t2) : tmap1(t1), tmap2(t2) {}

		std::string tempMap(std::shared_ptr<Temp> t) {
			std::string s = tmap1->tempMap(t);
			// not sure about string comparison
			if (s != "") {
				return s;
			}
			return tmap2->tempMap(t);
		}
	};
}