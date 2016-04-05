#include "ExpInterface.hpp"
#include "ExpList.hpp"

#include <memory>

namespace Tree {
	class BINOP : public Exp {
	public:
		int binop;
  		std::shared_ptr<Exp> left, right;
		static const int PLUS = 0, MINUS = 1, MUL = 2, DIV = 3, 
			AND = 4, OR = 5, LSHIFT = 6, RSHIFT = 7, ARSHIFT = 8, XOR = 9;

		BINOP(int _binop, std::shared_ptr<Exp> _left, std::shared_ptr<Exp> _right) 
			: binop(_binop), left(_left), right(_right) {}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(left, std::make_shared<ExpList>(ExpList(right, null)));
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
			return std::make_shared<BINOP>(binop, _kids.head, _kids.tail.head);
		}
	};
}