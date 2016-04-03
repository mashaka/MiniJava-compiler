#include <memory>

#include "Temp.hpp"
#include "Exp.hpp"
#include "ExpList.hpp"

namespace Tree {
	class MEM : public Exp {
	public:
		std::shared_ptr<Exp> exp;

		MEM(std::shared_ptr<Exp> _exp):
		exp(_exp)
		{}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(ExpList(exp, nullptr));
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
			return std::make_shared<Exp>(MEM(_kids.head));
		}
	};
}