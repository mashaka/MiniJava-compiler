#include "visitor.hpp"
#include "SymbolsTable.hpp"


using namespace SymbolsTable;

class CSymbolTableBuilder : public IVisitor {
public:
	bool inMethod;
	CClassInfo* curClass;
	CMethodInfo* curMethod;
	CTable symbTable; 
	const CSymbol* lastTypeValue;
	CStorage* symbols;

	CSymbolTableBuilder(CStorage* _symbols): symbols(_symbols) {}

	void visit(const Goal* n) {
		inMethod = false;
		n->e1->accept(this); //MainClass
		if(n->e2 != 0) {
			n->e2->accept(this); //ClassDeclarationList
		}
	}

	void visit(const MainClass* n) {
		if( symbTable.AddClass( symbols->Get( n->e1 ) ) ) {
			curClass = &symbTable.classesList.back();
			lastTypeValue = symbols->Get( "void" );
			if( curClass->AddMethod( symbols-> Get( "main" ), lastTypeValue ) ) {
				inMethod = true;
				curMethod = &curClass->methodsList.back();
				lastTypeValue = symbols->Get( "String[]" );
				if( curMethod->AddParam( symbols->Get( n->e1 ), lastTypeValue ) ) {
					n->e3->accept(this); //Statement
				}
			}
		}
	}

	void visit(const ClassDeclaration1* n) {}
	void visit(const ClassDeclaration2* n) {}

	void visit(const ClassDeclarationList* n) {}

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
}
