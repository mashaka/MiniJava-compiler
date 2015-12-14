#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Symbol.hpp"

namespace SymbolsTable {

	template <typename T>
	bool checkItemAlreadyExists(const std::vector<T>& items, const Symbol::CSymbol* itemName) {
		typename std::vector<T>::const_iterator it = items.cbegin();
		typename std::vector<T>::const_iterator itEnd = items.cend();
		for (; it != itEnd; ++it) {
			if (it->name == itemName) {
				std::cerr << "redefinition: " << itemName << std::endl;
				return true;
			}
		}
		return false;
	}

	struct CVarInfo {
		const Symbol::CSymbol* name;
		const Symbol::CSymbol* type;
		CVarInfo(const Symbol::CSymbol* _name, const Symbol::CSymbol* _type):
			name(_name), type(_type) {}
	};


	struct CMethodInfo {
		const Symbol::CSymbol* name;
		const Symbol::CSymbol* returnType;
		std::vector<CVarInfo> paramsList;
		std::vector<CVarInfo> varsList;
		CMethodInfo(const Symbol::CSymbol* _name, const Symbol::CSymbol* _returnType): 
			name(_name), returnType(_returnType), varsList(), paramsList() {}

		bool AddParam(const Symbol::CSymbol* name, const Symbol::CSymbol* type) {
			if(!checkItemAlreadyExists<CVarInfo>(paramsList, name)) {
				paramsList.push_back(CVarInfo(name, type));
				std::cout << "Add parametr: " << type->String() << " " << name->String() << std::endl;
				return true;	
			}
			return false;
		}

		bool AddVar(const Symbol::CSymbol* name, const Symbol::CSymbol* type) {
			if(!checkItemAlreadyExists<CVarInfo>(varsList, name)) {
				varsList.push_back(CVarInfo(name, type));
				std::cout << "Add variable: " << type->String() << " " << name->String() << std::endl;	
				return true;	
			}
			return false;
		}
	};

	struct CClassInfo {
		const Symbol::CSymbol* name;
		const Symbol::CSymbol* parent;
		std::vector<CVarInfo> varsList;
		std::vector<CMethodInfo> methodsList;
		CClassInfo(const Symbol::CSymbol* _name): name(_name), varsList(), methodsList() {}
		
		bool AddVar(const Symbol::CSymbol* name, const Symbol::CSymbol* type) {
			if(!checkItemAlreadyExists<CVarInfo>(varsList, name)) {
				varsList.push_back(CVarInfo(name, type));
				std::cout << "Add variable: " << type->String() << " " << name->String() << std::endl;
				return true;	
			}
			return false;
		}

		bool AddMethod(const Symbol::CSymbol* name, const Symbol::CSymbol* returnType) {
			if(!checkItemAlreadyExists<CMethodInfo>(methodsList, name)) {
				methodsList.push_back(CMethodInfo(name, returnType));
				std::cout << "Add method: " << returnType->String() << " " << name->String() << std::endl;
				return true;	
			}
			return false;
		}
	};

	struct CTable {
		std::vector<CClassInfo> classesList;
		CTable(): classesList() {}

		bool AddClass(const Symbol::CSymbol* name) {
			if(!checkItemAlreadyExists<CClassInfo>(classesList, name)) {
				classesList.push_back(CClassInfo(name));
				std::cout << "Add class: " << name->String() << std::endl;
				return true;	
			}
			return false;
		}
	};

}