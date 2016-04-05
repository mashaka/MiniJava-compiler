#include "StmList.hpp"
#include <memory>

namespace Canon {
	class StmListList {
	public:
		std::shared_ptr<Tree::StmList> head;
		std::shared_ptr<StmListList> tail;
		
		StmListList(std::shared_ptr<Tree::StmList> _head, std::shared_ptr<StmListList> _tail):
		head(_head),
		tail(_tail)
		{}
	};
}
