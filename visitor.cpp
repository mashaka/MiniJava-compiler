#include "visitor.hpp"

void printTabs(int tabsCount) {
	for(int i=0; i < tabsCount; ++i)
		printf("    ");
}

class Interpreter : public IVisitor {
public:
	int tabsCount;

	Interpreter() : tabsCount(0) {}

	void visit(const Goal* n) {
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "Goal");
		n->e1->accept(this); //MainClass
		if(n->e2 != 0) {
			n->e2->accept(this); //ClassDeclarationList
		}
		tabsCount--;
	}

	void visit(const MainClass* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MainClass");
		printTabs(tabsCount+1);	printf("CLASS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //valueString
		printTabs(tabsCount+1);	printf("{\n");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		printTabs(tabsCount+1); printf("STATIC\n");
		printTabs(tabsCount+1); printf("VOID\n");
		printTabs(tabsCount+1); printf("MAIN\n");
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf("STRING[]\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		printTabs(tabsCount+1); printf(")\n"); 
		printTabs(tabsCount+1); printf("{\n");
		n->e3->accept(this); //Statement
		printTabs(tabsCount+1); printf("}\n");
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const ClassDeclaration1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclaration1");
		printTabs(tabsCount+1); printf("CLASS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //valueString
		printTabs(tabsCount+1); printf("EXTENDS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		printTabs(tabsCount+1); printf("{\n");
		if(n->e3 != 0){
			n->e3->accept(this); //VarDeclarationList
		}
		if(n->e4 != 0) {
			n->e4->accept(this); //MethodDeclarationList
		}
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const ClassDeclaration2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclaration2");
		printTabs(tabsCount+1); printf("CLASS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //valueString
		printTabs(tabsCount+1); printf("{\n");
		if(n->e2 != 0){
			n->e2->accept(this); //VarDeclarationList
		}
		if(n->e3 != 0) {
			n->e3->accept(this); //MethodDeclarationList
		}
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const ClassDeclarationList* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclarationList");
		n->e1->accept(this); //ClassDeclaration
		if(n->e2 != 0) {
			n->e2->accept(this); //ClassDeclarationList
		}
		tabsCount--;
	}

	void visit(const VarDeclaration* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "VarDeclaration");
		n->e1->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		printTabs(tabsCount+1); printf(";\n");
		tabsCount--;
	}

	void visit(const VarDeclarationList* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "VarDeclarationList");
		if(n->e1 != 0) {
			n->e1->accept(this); //VarDeclarationList
		}
		n->e2->accept(this); //VarDeclaration
		tabsCount--;
	}

	void visit(const MethodDeclaration1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclaration1");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		n->e1->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e4).c_str()); //valueString
		if(n->e5 != 0) {
			n->e5->accept(this); //CommaTypeIdentifierList
		}
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf("{\n");
		if(n->e6 != 0){
			n->e6->accept(this); //VarDeclarationList
		}
		if(n->e7 != 0) {
			n->e7->accept(this); //StatementList
		}
		printTabs(tabsCount+1); printf("RETURN\n");
		n->e8->accept(this); //Expression
		printTabs(tabsCount+1); printf(";\n");
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const MethodDeclaration2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclaration2");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		n->e1->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf("{\n");
		if(n->e3 != 0){
			n->e3->accept(this); //VarDeclarationList
		}
		if(n->e4 != 0) {
			n->e4->accept(this); //StatementList
		}
		printTabs(tabsCount+1); printf("RETURN\n");
		n->e5->accept(this); //Expression
		printTabs(tabsCount+1); printf(";\n");
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const MethodDeclarationList* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclarationList");
		n->e1->accept(this); //MethodDeclaration
		if(n->e2 != 0) {
			n->e2->accept(this); //MethodDeclarationList
		}
		tabsCount--;
	}

	void visit(const CommaTypeIdentifierList* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "CommaTypeIdentifierList");
		printTabs(tabsCount+1); printf(",\n");
		n->e1->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		if(n->e3 != 0) {
			n->e3->accept(this); //CommaTypeIdentifierList
		}
		tabsCount--;
	}

	//Type 1
	void visit(const TypeIntArray* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "TypeIntArray");
		tabsCount--;
	}

	//Type 2
	void visit(const TypeBoolean* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "TypeBoolean");
		tabsCount--;
	}

	//Type 3
	void visit(const TypeInt* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "TypeInt");
		tabsCount--;
	}

	//Type 4
	void visit(const TypeIdentifier* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "TypeIdentifier");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //value
		tabsCount--;
	}

	void visit(const StatementListBraced* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementListBraced");
		printTabs(tabsCount+1); printf("{\n");
		if(n->e1 != 0) {
			n->e1->accept(this); //StatementList
		}
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const StatementIf* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementIf");
		printTabs(tabsCount+1); printf("if\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(")\n");
		n->e2->accept(this); //Statement
		printTabs(tabsCount+1); printf("else\n");
		n->e3->accept(this); //Statement
		tabsCount--;
	}

	void visit(const StatementWhile* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementWhile");
		printTabs(tabsCount+1); printf("while\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(")\n");
		n->e2->accept(this); //Statement
		tabsCount--;
	}

	void visit(const StatementPrint* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementPrint");
		printTabs(tabsCount+1); printf("print\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf(";\n");
		tabsCount--;
	}

	void visit(const StatementIdentifier1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementIdentifier1");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //valueString
		printTabs(tabsCount+1); printf("=\n");
		n->e2->accept(this); //Expression
		printTabs(tabsCount+1); printf(";\n");
		tabsCount--;
	}

	void visit(const StatementIdentifier2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementIdentifier2");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //valueString
		printTabs(tabsCount+1); printf("[\n");
		n->e2->accept(this); //Expression
		printTabs(tabsCount+1); printf("]\n");
		printTabs(tabsCount+1); printf("=\n");
		n->e3->accept(this); //Expression
		printTabs(tabsCount+1); printf(";\n");
		tabsCount--;
	}

	void visit(const StatementList* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementList");
		n->e1->accept(this); //Statement
		if(n->e2 != 0) {
			n->e2->accept(this); //StatementList
		}
		tabsCount--;
	}

	void visit(const ExpressionBinOp* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionBinOp");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("&&\n");
		n->e3->accept(this); //Expression
		tabsCount--;
	}
	// TODO add e2
	void visit(const ExpressionAriOp* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionAriOp");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("+\n");
		n->e3->accept(this); //Expression
		tabsCount--;
	}

	void visit(const ExpressionBracks* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionBracks");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("[\n");
		n->e2->accept(this); //Expression
		printTabs(tabsCount+1); printf("]\n");
		tabsCount--;
	}

	void visit(const ExpressionLength* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionLength");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("LENGTH\n");
		tabsCount--;
	}

	void visit(const ExpressionMethod* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionMethod");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this); //Expression
		if(n->e4 != 0) {
			n->e4->accept(this); //CommaExpressionList
		}
		printTabs(tabsCount+1); printf(")\n");
		tabsCount--;
	}

	void visit(const ExpressionEmptyMethod* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionEmptyMethod");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e2).c_str()); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
		tabsCount--;
	}

	void visit(const ExpressionNum* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionNum");
		printTabs(tabsCount+1); printf("INT(%s)\n", (n->e1).c_str()); //valueString
		tabsCount--;
	}

	void visit(const ExpressionLogOp* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionLogOp");
		printTabs(tabsCount+1); printf("true\n");
		tabsCount--;
	}

	void visit(const ExpressionId* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionId");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //value
		tabsCount--;
	}

	void visit(const ExpressionThis* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionThis");
		printTabs(tabsCount+1); printf("this\n");
		tabsCount--;
	}

	void visit(const ExpressionNew* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionNew");
		printTabs(tabsCount+1); printf("new\n");
		printTabs(tabsCount+1); printf("int\n");
		printTabs(tabsCount+1); printf("[\n");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("]\n");
		tabsCount--;
	}

	void visit(const ExpressionEmptyNew* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionEmptyNew");
		printTabs(tabsCount+1); printf("new\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", (n->e1).c_str()); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
		tabsCount--;
	}

	void visit(const ExpressionNot* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionNot");
		printTabs(tabsCount+1); printf("not\n");
		n->e1->accept(this); //Expression
		tabsCount--;
	}

	void visit(const ExpressionParens* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionParens");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(")\n");
		tabsCount--;
	}

	void visit(const CommaExpressionList* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "CommaExpressionList");
		printTabs(tabsCount+1); printf(",\n");
		n->e1->accept(this); //Expression
		if(n->e2 != 0) {
			n->e2->accept(this); //CommaExpressionList
		}
		tabsCount--;
	}
};
