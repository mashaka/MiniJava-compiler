#include "ExpList.hpp"
#include <memory>

namespace Tree {
	class Stm {
	public:
		virtual std::shared_ptr<ExpList> kids();
		virtual std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids);
	};
}
