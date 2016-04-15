#pragma once

#include <string>

namespace Temp {
	class Temp {
	public:
		Temp() {
			num = count++;
		}

		std::string toString() {
			// requires C++ 11 for to_string
			return "t" + std::to_string(num);
		}

	private:
		static int count;
		int num;
	};

	int Temp::count = 0;
}


