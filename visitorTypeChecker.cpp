#include "visitor.hpp"
#include "SymbolsTable.hpp"
#include <iostream>

class CTypeChecker : public IVisitor {
public:
	SymbolsTable::CTable table;
	const Symbol::CSymbol* lastTypeValue;
	Symbol::CStorage* symbols;
	const Symbol::CSymbol* curClassName;

	CTypeChecker(Symbol::CStorage* _symbols, SymbolsTable::CTable& _table): symbols(_symbols), table(_table) {}

	void checkVarExistenceAndGetType( const Symbol::CSymbol* name ) {
		for (int l = 0; l < table.classesList.size(); l++){
			for (int j = 0; j < table.classesList[l].methodsList.size(); j++){
				for (int i = 0; i < table.classesList[l].methodsList[j].varsList.size(); i++){
					if (name == table.classesList[l].methodsList[j].varsList[i].name) {
						lastTypeValue = table.classesList[l].methodsList[j].varsList[i].type;
						return;
					}
				}

				
				for (int i = 0; i < table.classesList[l].methodsList[j].paramsList.size(); i++){
				 	if (name == table.classesList[l].methodsList[j].paramsList[i].name) {
						lastTypeValue = table.classesList[l].methodsList[j].paramsList[i].type;
						return;
					}
				}

				
				for (int i = 0; i < table.classesList[l].varsList.size(); i++){
					if (name == table.classesList[l].varsList[i].name) {
						lastTypeValue = table.classesList[l].varsList[i].type;
						return;
					}
				}
				
			}
		}
		std::cout << "Var " << name->String() << " does not exist" << std::endl;
		lastTypeValue = symbols->Get("");
	}

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

	void checkMethodExistence(const Symbol::CSymbol* className) {
		bool doesExist = false;
		for( int i = 0; i < table.classesList.size(); i++ ){
			for( int j = 0; j < table.classesList[i].methodsList.size(); j++ ){
				if( table.classesList[i].methodsList[j].name == className ){
					lastTypeValue = table.classesList[i].methodsList[j].returnType;
					doesExist = true;
					break;
				}
			}
			if( doesExist ){
				break;
			}
		}
		if ( !doesExist ) {
			lastTypeValue = symbols->Get("");
			std::cout << "Method " << className->String() << " does not exist"<< std::endl;
		}
	}

	void checkIfNumber( const Symbol::CSymbol* className) {
		std::string value = className->String();
		std::string::const_iterator it = value.begin();
		while (it != value.end() && std::isdigit(*it)) ++it;
		if( it != value.end() ) {
			std::cout << "\"" << value << "\" is not a number"<< std::endl;
		}
	}

	void checkLastEqual( const Symbol::CSymbol* className ) {
		if( lastTypeValue != className ){
			std::cout << "Wrong return value" << std::endl;
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

	void visit(const VarDeclaration* n) {
		n->e1->accept(this); //Type
	}

	void visit(const VarDeclarationList* n) {
		if(n->e1 != 0) {
			n->e1->accept(this); //VarDeclarationList
		}
		n->e2->accept(this); //VarDeclaration
	}

	void visit(const MethodDeclaration1* n) {
		n->e1->accept(this); //Type

		n->e3->accept(this); //Type

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
	}

	void visit(const MethodDeclaration2* n) {
		n->e1->accept(this); //Type

		if(n->e3 != 0){
			n->e3->accept(this); //VarDeclarationList
		}
		if(n->e4 != 0) {
			n->e4->accept(this); //StatementList
		}
		n->e5->accept(this); //Expression
	}

	void visit(const MethodDeclarationList* n) {
		n->e1->accept(this); //MethodDeclaration
		if(n->e2 != 0) {
			n->e2->accept(this); //MethodDeclarationList
		}
	}

	void visit(const CommaTypeIdentifierList* n) {
		n->e1->accept(this); //Type
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
		checkClassExistence( lastTypeValue );
	}

	void visit(const StatementListBraced* n) {
		if(n->e1 != 0) {
			n->e1->accept(this); //StatementList
		}
	}

	void visit(const StatementIf* n) {
		n->e1->accept(this); //Expression
		if( lastTypeValue != symbols->Get( "bool" ) ) {
			std::cout << "Expression inside if is not boolean" << std::endl;
		}
		n->e2->accept(this); //Statement
		n->e3->accept(this); //Statement
	}

	void visit(const StatementWhile* n) {
		n->e1->accept(this); //Expression
		if( lastTypeValue != symbols->Get( "bool" ) ) {
			std::cout << "Expression inside while is not boolean" << std::endl;
		}
		n->e2->accept(this); //Statement
	}

	void visit(const StatementPrint* n) {
		n->e1->accept(this); //Expression
		if( lastTypeValue != symbols->Get( "int" ) ) {
			std::cout << "Expression inside print is not int, recieved " << lastTypeValue->String() << std::endl;
		}
	}

	void visit(const StatementIdentifier1* n) {
		
		checkVarExistenceAndGetType( symbols->Get( n->e1 ) );
		const Symbol::CSymbol* varType = lastTypeValue;

		n->e2->accept(this); //Expression
		if(varType != lastTypeValue) {
			std::cout << n->e1 << "can not be recieve such value" << std::endl;
		}
	}

	void visit(const StatementIdentifier2* n) {
		checkVarExistenceAndGetType( symbols->Get( n->e1 ) );
		const Symbol::CSymbol* varType = lastTypeValue;

		n->e2->accept(this); //Expression
		if( lastTypeValue != symbols->Get( "int" ) ) {
			std::cout << "Array " << n->e1 << " is not int" << std::endl;
		}

		n->e3->accept(this); //Expression
		if(varType != lastTypeValue) {
			std::cout << n->e1 << "Can not be recieve such value" << std::endl;
		}
	}

	void visit(const StatementList* n) {
		n->e1->accept(this); //Statement
		if(n->e2 != 0) {
			n->e2->accept(this); //StatementList
		}
	}

	void visit(const ExpressionBinOp* n) {
		n->e1->accept(this); //Expression
		if(n->e2 == B_LT) {
			checkLastEqual(symbols->Get("int"));
		} else {
			checkLastEqual(symbols->Get("bool"));
		}
		n->e3->accept(this); //Expression
		if(n->e2 == B_LT) {
			checkLastEqual(symbols->Get("int"));
		} else {
			checkLastEqual(symbols->Get("bool"));
		}
		lastTypeValue = symbols->Get("bool");
	}

	void visit(const ExpressionAriOp* n) {
		n->e1->accept(this); //Expression
		checkLastEqual(symbols->Get("int"));
		n->e3->accept(this); //Expression
		checkLastEqual(symbols->Get("int"));
		lastTypeValue = symbols->Get("int");
	}
	
	void visit(const ExpressionBracks* n) {
		n->e1->accept(this); //Expression
		n->e2->accept(this); //Expression
		checkLastEqual(symbols->Get("int"));
		lastTypeValue = symbols->Get("");
	}

	void visit(const ExpressionLength* n) {
		n->e1->accept(this); //Expression
		lastTypeValue = symbols->Get("int");
	}

	void visit(const ExpressionMethod* n) {
		n->e1->accept(this); //Expression
		const Symbol::CSymbol* symbol = symbols->Get( n->e2 );
		checkMethodExistence( symbol );
		const Symbol::CSymbol* returnType = lastTypeValue; 
		n->e3->accept(this); //Expression
		if(n->e4 != 0) {
			n->e4->accept(this); //CommaExpressionList
		}
		lastTypeValue = returnType;
	}

	void visit(const ExpressionEmptyMethod* n) {
		n->e1->accept(this);
		const Symbol::CSymbol* symbol = symbols->Get( n->e2 );
		checkMethodExistence( symbol );
		lastTypeValue = symbols->Get("");
	}
	
	void visit(const ExpressionNum* n) {
		const Symbol::CSymbol* symbol = symbols->Get( n->e1 );
		checkIfNumber( symbol );
		lastTypeValue = symbols->Get("int");
	}
	
	void visit(const ExpressionLogOp* n) {
		lastTypeValue = symbols->Get("bool");
	}

	void visit(const ExpressionId* n) {
		const Symbol::CSymbol* symbol = symbols->Get( n->e1 );
	}
	
	void visit(const ExpressionThis* n) {
		lastTypeValue = curClassName;
	}
	
	void visit(const ExpressionNew* n) {
		n->e1->accept(this);
		lastTypeValue = symbols->Get("int[]");
	}
	
	void visit(const ExpressionEmptyNew* n) {
		const Symbol::CSymbol* symbol = symbols->Get( n->e1 );
		checkClassExistence( symbol );
		lastTypeValue = symbols->Get( n->e1 );
	}

	void visit(const ExpressionNot* n) {
		n->e1->accept(this); //Expression
		checkLastEqual(symbols->Get("bool"));
		lastTypeValue = symbols->Get("bool");
	}

	void visit(const ExpressionParens* n) {
		n->e1->accept(this); //Expression
		lastTypeValue = symbols->Get("");
	}

	void visit(const CommaExpressionList* n) {
		n->e1->accept(this); //Expression
		if(n->e2 != 0) {
			n->e2->accept(this); //CommaExpressionList
		}
	}
};

