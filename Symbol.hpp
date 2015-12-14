#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

namespace Symbol {

	class CStorage;

	class CSymbol {
	public:
		CSymbol(const std::string& _name): name(_name) {}
		const std::string& String() const {
			return name;
		}
	private:
		static CStorage* symbolsDictionary;
		std::string name;
	};

	class CStorage {
	public:
		const CSymbol* Get(const std::string& s) {
			std::unordered_map<std::string, CSymbol*>::const_iterator got = dictionary.find(s);
			CSymbol* symbol;
			if ( got == dictionary.end() ){
				symbol = new CSymbol(s);
				dictionary.emplace(s, symbol);
			} 
			else {
				symbol = got->second;
			}

			return symbol;
		}
	private:
		std::unordered_map<std::string, CSymbol*> dictionary;
	};


}