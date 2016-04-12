#pragma once

#include "TempMap.hpp"
#include "TempObj.hpp"
#include <string>

namespace Temp {
	class CombineMap: public Temp::TempMap {
		std::shared_ptr<Temp::TempMap> tmap1, tmap2;
	public:
		CombineMap(std::shared_ptr<Temp::Temp> t1, std::shared_ptr<Temp::Temp> t2) : tmap1(t1), tmap2(t2) {}

		std::string tempMap(std::shared_ptr<Temp::Temp> t) {
			std::string s = tmap1->tempMap(t);
			// not sure about string comparison
			if s != "":
				return s
			return tmap2->tempMap(t);
		}
	};
}