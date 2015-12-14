#include "visitor.hpp"
#include "SymbolsTable.hpp"
#include <iostream>

class CTypeChecker : public IVisitor {
public:
	SymbolsTable::CTable table; 
	const Symbol::CSymbol* lastTypeValue;
	Symbol::CStorage* symbols;

	CTypeChecker(Symbol::CStorage* _symbols, SymbolsTable::CTable& _table): symbols(_symbols), table(_table) {}

	void checkCyclicInheritance(const Symbol::CSymbol* parent, const Symbol::CSymbol* child) {
		while( ( parent != child ) && ( parent != 0 ) ) {
			int i = 0;
			while ( ( table.classesList[i].name != parent ) )
				++i;
			parent = table.classesList[i].parent;
		}
		if( parent != 0 ) {
			std::cout << "Cyclic inheritance with " << child->String() << std::endl;
		}
	}

	void checkClassExistence(const Symbol::CSymbol* className) {
		int i = 0;
		while ( ( table.classesList[i].name != className ) && ( i < table.classesList.size() ) )
			++i;
		if ( i == table.classesList.size() ) {
			std::cout << "Class " << className->String() << " does not exist"<< std::endl;
		}
	}

	void visit(const Goal* n) {
		n->e1->accept(this); //MainClass
		if(n->e2 != 0) {
			n->e2->accept(this); //ClassDeclarationList
		}
	}

	void visit(const MainClass* n) {
		n->e3->accept(this); //Statement
	}

	void visit(const ClassDeclaration1* n) {
		const Symbol::CSymbol* child = symbols->Get( n->e2 );
		const Symbol::CSymbol* parent = symbols->Get( n->e2 );
		checkClassExistence(parent);
		checkCyclicInheritance(parent, child);
		if(n->e3 != 0){
			n->e3->accept(this); //VarDeclarationList
		}
		if(n->e4 != 0) {
			n->e4->accept(this); //MethodDeclarationList
		}
	}

	void visit(const ClassDeclaration2* n) {
		if(n->e2 != 0){
			n->e2->accept(this); //VarDeclarationList
		}
		if(n->e3 != 0) {
			n->e3->accept(this); //MethodDeclarationList
		}
	}

	void visit(const ClassDeclarationList* n) {
		n->e1->accept(this); //ClassDeclaration
		if(n->e2 != 0) {
			n->e2->accept(this); //ClassDeclarationList
		}
	}

	void visit(const VarDeclaration* n) {}

	void visit(const VarDeclarationList* n) {}

	void visit(const MethodDeclaration1* n) {}
	void visit(const MethodDeclaration2* n) {}

	void visit(const MethodDeclarationList* n) {}

	void visit(const CommaTypeIdentifierList* n) {}

	void visit(const TypeIntArray* n) {}
	void visit(const TypeBoolean* n) {}
	void visit(const TypeInt* n) {}
	void visit(const TypeIdentifier* n) {}

	void visit(const StatementListBraced* n) {}
	void visit(const StatementIf* n) {}
	void visit(const StatementWhile* n) {}
	void visit(const StatementPrint* n) {}
	void visit(const StatementIdentifier1* n) {}
	void visit(const StatementIdentifier2* n) {}

	void visit(const StatementList* n) {}

	void visit(const ExpressionBinOp* n) {}
	void visit(const ExpressionAriOp* n) {}
	void visit(const ExpressionBracks* n) {}
	void visit(const ExpressionLength* n) {}
	void visit(const ExpressionMethod* n) {}
	void visit(const ExpressionEmptyMethod* n) {}
	void visit(const ExpressionNum* n) {}
	void visit(const ExpressionLogOp* n) {}
	void visit(const ExpressionId* n) {}
	void visit(const ExpressionThis* n) {}
	void visit(const ExpressionNew* n) {}
	void visit(const ExpressionEmptyNew* n) {}
	void visit(const ExpressionNot* n) {}
	void visit(const ExpressionParens* n) {}

	void visit(const CommaExpressionList* n) {}
};

