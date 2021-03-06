#pragma once
#include "Symbol.hpp"
#include <string>

// A Label represents an address in assembly language.

namespace Temp {
	class Label {
	public:
		Label(std::string _name) : name(_name) {}

		Label() {
			// requires C++ 11 for to_string
			name =  "L" + std::to_string(count++);
		}

		// Makes a new label whose name is the same as a symbol
		Label(const Symbol::CSymbol& s) {
			name = s.String();
		}

		// a printable representation of the label, for use in assembly language output.
		std::string toString() {
			return name;
		}

	private:
		std::string name;
		static int count;
	};

}