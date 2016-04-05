#include <memory>

#include "TempObj.hpp"
#include "StmInterface.hpp"
#include "ExpInterface.hpp"
#include "ExpList.hpp"

namespace Tree {
	class MOVE : public Stm {
	public:
		std::shared_ptr<Exp> dst, src;

		MOVE(std::shared_ptr<Exp> _dst, std::shared_ptr<Exp> _src):
		dst(_dst), src(_src)
		{}

		std::shared_ptr<ExpList> kids() {
			if (MEM newDst = dynamic_cast<MEM>(*dst)) {
				return std::make_shared<ExpList>(ExpList(newDst.exp, ExpList(src, nullptr)));
			} else {
				return std::make_shared<ExpList>(ExpList(src, nullptr));
			}
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
			if (dynamic_cast<MEM>(*dst)) {
				return std::make_shared<MOVE>(MOVE(MEM(_kids.head), _kids.tail.head));
			} else {
				return std::make_shared<MOVE>(MOVE(dst, _kids.head));
			}
		}
	};
}