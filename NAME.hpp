#include "ExpList.hpp"
#include "LabelObj.hpp"
#include "ExpInterface.hpp"
#include <memory>

namespace Tree {
	class NAME : public Exp {
	public:
		std::shared_ptr<Label> label;

		NAME(std::shared_ptr<Label> _label):
		label(_label)
		{}

		std::shared_ptr<ExpList> kids() {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
			return std::make_shared<Exp>(*this);
		}
	};
}
