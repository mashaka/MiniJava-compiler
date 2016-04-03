#include "Temp.hpp"
#include "ExpList.hpp"
// Маша должна написать этот файл :)
#include "Label.hpp"
// Никита должен написать этот файл :)
#include "Stm.hpp"

#include <memory>

namespace Tree {
	class LABEL : public Stm {
	public:
		std::shared_ptr<Label> label;
		
		LABEL(std::shared_ptr<Label> _label):
		label(_label)
		{}

		std::shared_ptr<ExpList> kids() {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
			return std::make_shared<Stm>(*this);
		}
	};
}