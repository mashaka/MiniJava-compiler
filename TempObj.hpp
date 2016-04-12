#pragma once

#include <string>

namespace Temp {
	class Temp {
	private:
		static int count;
		int num;
	public:
		Temp() {
			num = count++;
		}

		std::string toString() {
			// requires C++ 11 for to_string
			return "t" + std::to_string(num);
		}
	};
}