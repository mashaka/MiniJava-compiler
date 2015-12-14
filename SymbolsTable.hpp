#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Symbol.hpp"

using namespace Symbol;

namespace SymbolsTable {

	template <typename T>
	bool checkItemAlreadyExists(const std::vector<T>& items, const CSymbol* itemName) {
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
		const CSymbol* name;
		const CSymbol* type;
		CVarInfo(const CSymbol* _name, const CSymbol* _type):
			name(_name), type(_type) {}
	};


	struct CMethodInfo {
		const CSymbol* name;
		const CSymbol* returnType;
		std::vector<CVarInfo> paramsList;
		std::vector<CVarInfo> varsList;
		CMethodInfo(const CSymbol* _name, const CSymbol* _returnType): 
			name(_name), returnType(_returnType), varsList(), paramsList() {}

		bool AddParam(const CSymbol* name, const CSymbol* type) {
			if(!checkItemAlreadyExists<CVarInfo>(paramsList, name)) {
				paramsList.push_back(CVarInfo(name, type));
				printf( "Add parametr: %s %s\n", type->String().c_str(), name->String().c_str() );
				return true;	
			}
			return false;
		}

		bool AddVar(const CSymbol* name, const CSymbol* type) {
			if(!checkItemAlreadyExists<CVarInfo>(varsList, name)) {
				varsList.push_back(CVarInfo(name, type));	
				return true;	
			}
			return false;
		}
	};

	struct CClassInfo {
		const CSymbol* name;
		std::vector<CVarInfo> varsList;
		std::vector<CMethodInfo> methodsList;
		CClassInfo(const CSymbol* _name): name(_name), varsList(), methodsList() {}
		
		bool AddVar(const CSymbol* name, const CSymbol* type) {
			if(!checkItemAlreadyExists<CVarInfo>(varsList, name)) {
				varsList.push_back(CVarInfo(name, type));
				return true;	
			}
			return false;
		}

		bool AddMethod(const CSymbol* name, const CSymbol* returnType) {
			if(!checkItemAlreadyExists<CMethodInfo>(methodsList, name)) {
				methodsList.push_back(CMethodInfo(name, returnType));
				return true;	
			}
			return false;
		}
	};

	struct CTable {
		std::vector<CClassInfo> classesList;
		CTable(): classesList() {}

		bool AddClass(const CSymbol* name) {
			if(!checkItemAlreadyExists<CClassInfo>(classesList, name)) {
				classesList.push_back(CClassInfo(name));
				return true;	
			}
			return false;
		}
	};

}