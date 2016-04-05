#include "LabelObj.hpp"
#include <memory>

namespace Temp {
	class LabelList {
	public:
		std::shared_ptr<Label> head;
		std::shared_ptr<LabelList> tail;

		LabelList(std::shared_ptr<Label> _head, std::shared_ptr<LabelList> _tail)
			: head(_head), tail(_tail) {}
	};
}