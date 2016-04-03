#include <memory>

#include "Temp.hpp"
#include "Exp.hpp"
#include "ExpList.hpp"
// Маша должна написать эти файлы :)
#include "Label.hpp"
#include "LabelList.hpp"
// Никита должен написать эти файлы :)
#include "Stm.hpp"
#include "NAME.hpp"

namespace Tree {
	class JUMP : public Stm {
	public:
		std::shared_ptr<Exp> exp;
		std::shared_ptr<Temp::LabelList> targets;

		JUMP(std::shared_ptr<Exp> _exp, std::shared_ptr<Temp::LabelList> _targets):
		exp(_exp), targets(_targets) 
		{}

		JUMP(std::shared_ptr<Temp::Label> _target) {
			// requires C++ 11 for nullptr
			this = new JUMP(NAME(_target), Temp::LabelList(_target, nullptr));
		}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(ExpList(exp, nullptr));
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
			return std::make_shared<JUMP>(JUMP(_kids.head, targets));
		}
	};
}