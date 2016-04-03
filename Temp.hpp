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
			// requires C++ 11
			return "t" + std::to_string(num);
		}
	};
}