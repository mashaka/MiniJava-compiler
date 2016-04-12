#pragma once
#include "Symbol.hpp"
#include <string>

// A Label represents an address in assembly language.

namespace Temp {
	class Label {
	public:
		Label(string _name) : name(_name) {}

		Label() {
			// requires C++ 11 for to_string
			name =  "L" + std::to_string(num++);
		}

		// Makes a new label whose name is the same as a symbol
		Label(const CSymbol& s) {
			name = s.String();
		}

		// a printable representation of the label, for use in assembly language output.
		string toString() {
			return name;
		}

	private:
		string name;
		static int count;
	};

}