#pragma once

#include "TempObj.hpp"
#include <memory>

namespace Temp {
	class TempList {
	public:
		std::shared_ptr<Temp> head;
		std::shared_ptr<TempList> tail;

		TempList(std::shared_ptr<Temp> _head, std::shared_ptr<TempList> _tail):
		head(_head), tail(_tail)
		{}
	};
}