#include "Stm.hpp"
#include <memory>

namespace Tree {
	class StmList {
	public:
		std::shared_ptr<Stm> head;
		std::shared_ptr<StmList> tail;
		
		StmList(std::shared_ptr<Stm> _head, std::shared_ptr<StmList> _tail):
		head(_head),
		tail(_tail)
		{}
	};
}