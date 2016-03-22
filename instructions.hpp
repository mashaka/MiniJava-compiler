#pragma once

#include "Symbol.hpp"
#include "IRTree.hpp"

class CInstructions {
public:
	CInstructions(Symbol::CSymbol* _name ): name(_name) {}

	const IRTree::Node* Get(size_t index) const
	{
		return &(instructions[index]);
	}

	void Add(const IRTree::Node instruction) 
	{
		instruction.push_back(instruction);
	}

private:
	Symbol::CSymbol *name; // имя функции
	std::vector<IRTree::Node> instructions; // инструкции функции на псевдо ассемблере
};