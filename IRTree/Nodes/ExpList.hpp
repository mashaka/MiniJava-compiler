#pragma once

#include "ExpInterface.hpp"
#include <memory>

namespace Tree {
	class Exp;

	class ExpList {
	public:
		std::shared_ptr<Exp> head;
		std::shared_ptr<ExpList> tail;
		
		ExpList(std::shared_ptr<Exp> _head, std::shared_ptr<ExpList> _tail):
		head(_head), tail(_tail)
		{}
	};
}
