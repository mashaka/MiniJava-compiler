#include "visitor.hpp"

void printTabs(int tabsCount) {
	for(int i=0; i < tabsCount; ++i)
		printf("\t");
}

class Interpreter : public IVisitor {
	int tabsCount;

	Interpreter() : tabsCount(0) {}

	void visit(const Goal* n) {
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "Goal");
		n->e1->accept(this); //MainClass
		n->e2->accept(this); //ClassDeclarationStar
		tabsCount--;
	}

	void visit(const MainClass* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MainClass");
		printTabs(tabsCount+1);	printf("CLASS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1);	printf("{\n");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		printTabs(tabsCount+1); printf("STATIC\n");
		printTabs(tabsCount+1); printf("VOID\n");
		printTabs(tabsCount+1); printf("MAIN\n");
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf("STRING[]\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
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
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("EXTENDS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("{\n");
		n->e3->accept(this); //VarDeclarationStar
		n->e4->accept(this); //MethodDeclarationStar
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const ClassDeclaration2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclaration2");
		printTabs(tabsCount+1); printf("CLASS\n", );
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("{\n");
		n->e2->accept(this); //VarDeclarationStar
		n->e3->accept(this); //MethodDeclarationStar
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const ClassDeclarationStar1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclarationStar1");
		printTabs(tabsCount+1); printf("empty\n");
		tabsCount--;
	}

	void visit(const ClassDeclarationStar2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclarationStar2");
		n->e1->accept(this); //ClassDeclaration
		n->e2->accept(this); //ClassDeclarationStar
		tabsCount--;
	}

	void visit(const VarDeclaration* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "VarDeclaration");
		n->e1->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf(";\n");
		tabsCount--;
	}

	void visit(const VarDeclarationStar1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "VarDeclarationStar1");
		printTabs(tabsCount+1); printf("empty\n");
		tabsCount--;
	}

	void visit(const VarDeclarationStar2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "VarDeclarationStar2");
		n->e1->accept(this); //VarDeclarationStar
		n->e2->accept(this); //VarDeclaration
		tabsCount--;
	}

	void visit(const MethodDeclaration1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclaration1");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		n->e1->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e4); //valueString
		n->e5->accept(this); //CommaTypeIdentifierStar
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf("{\n");
		n->e6->accept(this); //VarDeclarationStar
		n->e7->accept(this); //StatementStar
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
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf("{\n");
		n->e3->accept(this); //VarDeclarationStar
		n->e4->accept(this); //StatementStar
		printTabs(tabsCount+1); printf("RETURN\n");
		n->e5->accept(this); //Expression
		printTabs(tabsCount+1); printf(";\n");
		printTabs(tabsCount+1); printf("}\n");
		tabsCount--;
	}

	void visit(const MethodDeclarationStar1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclarationStar1");
		printTabs(tabsCount+1); printf("empty\n");
		tabsCount--;
	}

	void visit(const MethodDeclarationStar2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclarationStar2");
		n->e1->accept(this); //MethodDeclaration
		n->e2->accept(this); //MethodDeclarationStar
		tabsCount--;
	}

	void visit(const CommaTypeIdentifierStar1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "CommaTypeIdentifierStar1");
		printTabs(tabsCount+1); printf("empty\n");
		tabsCount--;
	}

	void visit(const CommaTypeIdentifierStar2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "CommaTypeIdentifierStar2");
		printTabs(tabsCount+1); printf(",\n");
		n->e1->accept(this); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		n->e3->accept(this); //CommaTypeIdentifierStar
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
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //value
		tabsCount--;
	}

	void visit(const StatementStarBraced* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementStarBraced");
		printTabs(tabsCount+1); printf("{\n");
		n->e1->accept(this); //StatementStar
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
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("=\n");
		n->e2->accept(this); //Expression
		printTabs(tabsCount+1); printf(";\n");
		tabsCount--;
	}

	void visit(const StatementIdentifier2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementIdentifier2");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("[\n");
		n->e2->accept(this); //Expression
		printTabs(tabsCount+1); printf("]\n");
		printTabs(tabsCount+1); printf("=\n");
		n->e3->accept(this); //Expression
		printTabs(tabsCount+1); printf(";\n");
		tabsCount--;
	}

	void visit(const StatementStar1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementStar1");
		printTabs(tabsCount+1); printf("empty\n");
		tabsCount--;
	}

	void visit(const StatementStar2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "StatementStar2");
		n->e1->accept(this); //Statement
		n->e2->accept(this); //StatementStar
		tabsCount--;
	}

	void visit(const ExpressionAndAnd* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionAndAnd");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("&&\n");
		n->e2->accept(this); //Expression
		tabsCount--;
	}

	void visit(const ExpressionLessThen* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionLessThen");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("<\n");
		n->e2->accept(this); //Expression
		tabsCount--;
	}

	void visit(const ExpressionPlus* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionPlus");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("+\n");
		n->e2->accept(this); //Expression
		tabsCount--;
	}

	void visit(const ExpressionMinus* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionMinus");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("-\n");
		n->e2->accept(this); //Expression
		tabsCount--;
	}

	void visit(const ExpressionMult* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionMult");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf("*\n");
		n->e2->accept(this); //Expression
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
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this); //Expression
		n->e4->accept(this); //CommaExpressionStar
		printTabs(tabsCount+1); printf(")\n");
		tabsCount--;
	}

	void visit(const ExpressionEmptyMethod* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionEmptyMethod");
		n->e1->accept(this); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
		tabsCount--;
	}

	void visit(const ExpressionNum* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionNum");
		printTabs(tabsCount+1); printf("INT(%s)\n", n->e1); //valueString
		tabsCount--;
	}

	void visit(const ExpressionTrue* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionTrue");
		printTabs(tabsCount+1); printf("true\n");
		tabsCount--;
	}

	void visit(const ExpressionFalse* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionFalse");
		printTabs(tabsCount+1); printf("false\n");
		tabsCount--;
	}

	void visit(const ExpressionId* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "ExpressionId");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //value
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
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
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

	void visit(const CommaExpressionStar1* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "CommaExpressionStar1");
		printTabs(tabsCount+1); printf("empty\n");
		tabsCount--;
	}

	void visit(const CommaExpressionStar2* n){
		tabsCount++;
		printTabs(tabsCount); 	printf("%s\n", "CommaExpressionStar2");
		printTabs(tabsCount+1); printf(",\n");
		n->e1->accept(this); //Expression
		n->e2->accept(this); //CommaExpressionStar
		tabsCount--;
	}
};
