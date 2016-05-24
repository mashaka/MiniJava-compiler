#pragma once

#include "Instr.hpp"

#include <memory>


namespace Assem {

class Instr;

class InstrList {
public:
	std::shared_ptr<Instr> head;
	std::shared_ptr<InstrList> tail;

	InstrList(std::shared_ptr<Instr> _head, std::shared_ptr<InstrList> _tail)
		: head(_head), tail(_tail) {}
};

}
