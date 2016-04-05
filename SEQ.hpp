#include "Temp.hpp"
#include "ExpList.hpp"
#include "Label.hpp"
#include "Stm.hpp"

#include <memory>

namespace Tree {
	class SEQ : public Stm {
	public:
		std::shared_ptr<Stm> left, right;
		
		SEQ(std::shared_ptr<Stm> _left, std::shared_ptr<Stm> _right):
		left(_left),
		right(_right)
		{}

		std::shared_ptr<ExpList> kids() {
			throw "kids() not applicable to SEQ";
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
			throw "kids() not applicable to SEQ";
		}
	};
}