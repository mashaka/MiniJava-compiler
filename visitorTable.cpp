#include "visitor.hpp"
#include "SymbolsTable.hpp"

class CSymbolTableBuilder : public IVisitor {
public:
	bool inMethod;
	SymbolsTable::CClassInfo* curClass;
	SymbolsTable::CMethodInfo* curMethod;
	SymbolsTable::CTable table; 
	const Symbol::CSymbol* lastTypeValue;
	Symbol::CStorage* symbols;

	CSymbolTableBuilder(Symbol::CStorage* _symbols): symbols(_symbols) {}

	void visit(const Goal* n) {
		inMethod = false;
		n->e1->accept(this); //MainClass
		if(n->e2 != 0) {
			n->e2->accept(this); //ClassDeclarationList
		}
	}

	void visit(const MainClass* n) {
		if( table.AddClass( symbols->Get( n->e1 ) ) ) {
			curClass = &table.classesList.back();
			lastTypeValue = symbols->Get( "void" );
			if( curClass->AddMethod( symbols-> Get( "main" ), lastTypeValue ) ) {
				inMethod = true;
				curMethod = &curClass->methodsList.back();
				lastTypeValue = symbols->Get( "String[]" );
				if( curMethod->AddParam( symbols->Get( n->e2 ), lastTypeValue ) ) {
					n->e3->accept(this); //Statement
					inMethod = false;
				}
			}
		}
	}

	void visit(const ClassDeclaration1* n) {
		if( table.AddClass( symbols->Get( n->e1 ) ) ) {
			curClass = &table.classesList.back();
			curClass->parent = symbols->Get( n->e2 );
			if(n->e3 != 0){
				n->e3->accept(this); //VarDeclarationList
			}
			if(n->e4 != 0) {
				n->e4->accept(this); //MethodDeclarationList
			}
		}
	}


	void visit(const ClassDeclaration2* n) {
		if( table.AddClass( symbols->Get( n->e1 ) ) ) {
			curClass = &table.classesList.back();
			if(n->e2 != 0){
				n->e2->accept(this); //VarDeclarationList
			}
			if(n->e3 != 0) {
				n->e3->accept(this); //MethodDeclarationList
			}
		}
	}

	void visit(const ClassDeclarationList* n) {
		n->e1->accept(this); //ClassDeclaration
		if(n->e2 != 0) {
			n->e2->accept(this); //ClassDeclarationList
		}
	}

	void visit(const VarDeclaration* n) {
		n->e1->accept(this); //Type
		if( inMethod ) {
			curMethod->AddVar( symbols->Get( n->e2 ), lastTypeValue );
		} else {
			curClass->AddVar( symbols->Get( n->e2 ), lastTypeValue );
		}
	}

	void visit(const VarDeclarationList* n) {
		if(n->e1 != 0) {
			n->e1->accept(this); //VarDeclarationList
		}
		n->e2->accept(this); //VarDeclaration
	}

	void visit(const MethodDeclaration1* n) {
		n->e1->accept(this); //Type
		curClass->AddMethod( symbols->Get( n->e2 ), lastTypeValue );

		inMethod = true;
		curMethod = &curClass->methodsList.back();

		n->e3->accept(this); //Type
		curMethod->AddParam(symbols->Get( n->e4 ), lastTypeValue );

		if(n->e5 != 0) {
			n->e5->accept(this); //CommaTypeIdentifierList
		}
		if(n->e6 != 0){
			n->e6->accept(this); //VarDeclarationList
		}
		if(n->e7 != 0) {
			n->e7->accept(this); //StatementList
		}
		
		n->e8->accept(this); //Expression
		inMethod = false;
	}

	void visit(const MethodDeclaration2* n) {
		n->e1->accept(this); //Type
		curClass->AddMethod( symbols->Get( n->e2 ), lastTypeValue );

		inMethod = true;
		curMethod = &curClass->methodsList.back();

		if(n->e3 != 0){
			n->e3->accept(this); //VarDeclarationList
		}
		if(n->e4 != 0) {
			n->e4->accept(this); //StatementList
		}
		n->e5->accept(this); //Expression
		inMethod = false;
	}

	void visit(const MethodDeclarationList* n) {
		n->e1->accept(this); //MethodDeclaration
		if(n->e2 != 0) {
			n->e2->accept(this); //MethodDeclarationList
		}
	}

	void visit(const CommaTypeIdentifierList* n) {
		n->e1->accept(this); //Type

		curMethod->AddParam(symbols->Get( n->e2 ), lastTypeValue );
		if(n->e3 != 0) {
			n->e3->accept(this); //CommaTypeIdentifierList
		}
	}

	void visit(const TypeIntArray* n) {
		lastTypeValue = symbols->Get( "int[]" );
	}

	void visit(const TypeBoolean* n) {
		lastTypeValue = symbols->Get( "bool" );
	}

	void visit(const TypeInt* n) {
		lastTypeValue = symbols->Get( "int" );
	}

	void visit(const TypeIdentifier* n) {
		lastTypeValue = symbols->Get( n->e1 );
	}

	void visit(const StatementListBraced* n) {
		if(n->e1 != 0) {
			n->e1->accept(this); //StatementList
		}
	}

	void visit(const StatementIf* n) {
		n->e1->accept(this); //Expression
		n->e2->accept(this); //Statement
		n->e3->accept(this); //Statement
	}

	void visit(const StatementWhile* n) {
		n->e1->accept(this); //Expression
		n->e2->accept(this); //Statement
	}

	void visit(const StatementPrint* n) {
		n->e1->accept(this); //Expression
	}

	void visit(const StatementIdentifier1* n) {
		n->e2->accept(this); //Expression
	}

	void visit(const StatementIdentifier2* n) {
		n->e2->accept(this); //Expression
		n->e3->accept(this); //Expression
	}

	void visit(const StatementList* n) {
		n->e1->accept(this); //Statement
		if(n->e2 != 0) {
			n->e2->accept(this); //StatementList
		}
	}

	void visit(const ExpressionBinOp* n) {
		n->e1->accept(this); //Expression
		n->e3->accept(this); //Expression		
	}

	void visit(const ExpressionAriOp* n) {
		n->e1->accept(this); //Expression
		n->e3->accept(this); //Expression
	}
	
	void visit(const ExpressionBracks* n) {
		n->e1->accept(this); //Expression
		n->e2->accept(this); //Expression
	}

	void visit(const ExpressionLength* n) {
		n->e1->accept(this); //Expression
	}

	void visit(const ExpressionMethod* n) {
		n->e1->accept(this); //Expression
		n->e3->accept(this); //Expression
		if(n->e4 != 0) {
			n->e4->accept(this); //CommaExpressionList
		}
	}
	
	void visit(const ExpressionEmptyMethod* n) {
		n->e1->accept(this); //Expression
	}
	
	void visit(const ExpressionNum* n) {}
	
	void visit(const ExpressionLogOp* n) {}

	void visit(const ExpressionId* n) {}

	void visit(const ExpressionThis* n) {}
	
	void visit(const ExpressionNew* n) {
		n->e1->accept(this);
	}

	void visit(const ExpressionEmptyNew* n) {}

	void visit(const ExpressionNot* n) {
		n->e1->accept(this); //Expression
	}

	void visit(const ExpressionParens* n) {
		n->e1->accept(this); //Expression
	}

	void visit(const CommaExpressionList* n) {
		n->e1->accept(this); //Expression
		if(n->e2 != 0) {
			n->e2->accept(this); //CommaExpressionList
		}
	}
};
