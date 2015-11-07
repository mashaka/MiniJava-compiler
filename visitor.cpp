#include "visitor.hpp"

void printTabs(int tabsCount) {
	for(int i=0; i < tabsCount; ++i)
		printf("\t");
}

class Interpreter : public IVisitor {
	void visit(const Goal* n, int tabsCount) {
		printTabs(tabsCount); 	printf("%s\n", "Goal");
		n->e1->accept(this, tabsCount + 1); //MainClass
		n->e2->accept(this, tabsCount + 1); //ClassDeclarationStar
	}
	void visit(const MainClass* n, int tabsCount){
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
		n->e3->accept(this, tabsCount + 1); //Statement
		printTabs(tabsCount+1); printf("}\n");
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const ClassDeclaration1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclaration1");
		printTabs(tabsCount+1); printf("CLASS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("EXTENDS\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("{\n");
		n->e3->accept(this, tabsCount + 1); //VarDeclarationStar
		n->e4->accept(this, tabsCount + 1); //MethodDeclarationStar
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const ClassDeclaration2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclaration2");
		printTabs(tabsCount+1); printf("CLASS\n", );
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("{\n");
		n->e2->accept(this, tabsCount + 1); //VarDeclarationStar
		n->e3->accept(this, tabsCount + 1); //MethodDeclarationStar
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const ClassDeclarationStar1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclarationStar1");
		printTabs(tabsCount+1); printf("empty\n");
	}

	void visit(const ClassDeclarationStar2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclarationStar2");
		n->e1->accept(this, tabsCount + 1); //ClassDeclaration
		n->e2->accept(this, tabsCount + 1); //ClassDeclarationStar
	}

	void visit(const VarDeclaration* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "VarDeclaration");
		n->e1->accept(this, tabsCount + 1); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf(";\n");
	}

	void visit(const VarDeclarationStar1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "VarDeclarationStar1");
		printTabs(tabsCount+1); printf("empty\n");
	}

	void visit(const VarDeclarationStar2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "VarDeclarationStar2");
		n->e1->accept(this, tabsCount + 1); //VarDeclarationStar
		n->e2->accept(this, tabsCount + 1); //VarDeclaration
	}

	void visit(const MethodDeclaration1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclaration1");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		n->e1->accept(this, tabsCount + 1); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this, tabsCount + 1); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e4); //valueString
		n->e5->accept(this, tabsCount + 1); //CommaTypeIdentifierStar
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf("{\n");
		n->e6->accept(this, tabsCount + 1); //VarDeclarationStar
		n->e7->accept(this, tabsCount + 1); //StatementStar
		printTabs(tabsCount+1); printf("RETURN\n");
		n->e8->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(";\n");
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const MethodDeclaration2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclaration2");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		n->e1->accept(this, tabsCount + 1); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf("{\n");
		n->e3->accept(this, tabsCount + 1); //VarDeclarationStar
		n->e4->accept(this, tabsCount + 1); //StatementStar
		printTabs(tabsCount+1); printf("RETURN\n");
		n->e5->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(";\n");
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const MethodDeclarationStar1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclarationStar1");
		printTabs(tabsCount+1); printf("empty\n");
	}

	void visit(const MethodDeclarationStar2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclarationStar2");
		n->e1->accept(this, tabsCount + 1); //MethodDeclaration
		n->e2->accept(this, tabsCount + 1); //MethodDeclarationStar
	}

	void visit(const CommaTypeIdentifierStar1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "CommaTypeIdentifierStar1");
		printTabs(tabsCount+1); printf("empty\n");
	}

	void visit(const CommaTypeIdentifierStar2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "CommaTypeIdentifierStar2");
		printTabs(tabsCount+1); printf(",\n");
		n->e1->accept(this, tabsCount + 1); //Type
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		n->e3->accept(this, tabsCount + 1); //CommaTypeIdentifierStar
	}

	//Type 1
	void visit(const TypeIntArray* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeIntArray");
	}

	//Type 2
	void visit(const TypeBoolean* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeBoolean");
	}

	//Type 3
	void visit(const TypeInt* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeInt");
	}

	//Type 4
	void visit(const TypeIdentifier* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeIdentifier");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //value
	}

	void visit(const StatementStarBraced* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementStarBraced");
		printTabs(tabsCount+1); printf("{\n");
		n->e1->accept(this, tabsCount + 1); //StatementStar
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const StatementIf* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementIf");
		printTabs(tabsCount+1); printf("if\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(")\n");
		n->e2->accept(this, tabsCount + 1); //Statement
		printTabs(tabsCount+1); printf("else\n");
		n->e3->accept(this, tabsCount + 1); //Statement
	}

	void visit(const StatementWhile* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementWhile");
		printTabs(tabsCount+1); printf("while\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(")\n");
		n->e2->accept(this, tabsCount + 1); //Statement
	}

	void visit(const StatementPrint* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementPrint");
		printTabs(tabsCount+1); printf("print\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf(";\n");
	}

	void visit(const StatementIdentifier1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementIdentifier1");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("=\n");
		n->e2->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(";\n");
	}

	void visit(const StatementIdentifier2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementIdentifier2");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("[\n");
		n->e2->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("]\n");
		printTabs(tabsCount+1); printf("=\n");
		n->e3->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(";\n");
	}

	void visit(const StatementStar1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementStar1");
		printTabs(tabsCount+1); printf("empty\n");
	}

	void visit(const StatementStar2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "StatementStar2");
		n->e1->accept(this, tabsCount + 1); //Statement
		n->e2->accept(this, tabsCount + 1); //StatementStar
	}

	void visit(const ExpressionAndAnd* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionAndAnd");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("&&\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const ExpressionLessThen* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionLessThen");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("<\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const ExpressionPlus* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionPlus");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("+\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const ExpressionMinus* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionMinus");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("-\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const ExpressionMult* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionMult");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("*\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const ExpressionBracks* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionBracks");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("[\n");
		n->e2->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("]\n");
	}

	void visit(const ExpressionLength* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionLength");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("LENGTH\n");
	}

	void visit(const ExpressionMethod* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionMethod");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this, tabsCount + 1); //Expression
		n->e4->accept(this, tabsCount + 1); //CommaExpressionStar
		printTabs(tabsCount+1); printf(")\n");
	}

	void visit(const ExpressionEmptyMethod* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionEmptyMethod");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e2); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
	}

	void visit(const ExpressionNum* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionNum");
		printTabs(tabsCount+1); printf("INT(%s)\n", n->e1); //valueString
	}

	void visit(const ExpressionTrue* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionTrue");
		printTabs(tabsCount+1); printf("true\n");
	}

	void visit(const ExpressionFalse* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionFalse");
		printTabs(tabsCount+1); printf("false\n");
	}

	void visit(const ExpressionId* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionId");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //value
	}

	void visit(const ExpressionThis* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionThis");
		printTabs(tabsCount+1); printf("this\n");
	}

	void visit(const ExpressionNew* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionNew");
		printTabs(tabsCount+1); printf("new\n");
		printTabs(tabsCount+1); printf("int\n");
		printTabs(tabsCount+1); printf("[\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("]\n");
	}

	void visit(const ExpressionEmptyNew* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionEmptyNew");
		printTabs(tabsCount+1); printf("new\n");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //valueString
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
	}

	void visit(const ExpressionNot* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionNot");
		printTabs(tabsCount+1); printf("not\n");
		n->e1->accept(this, tabsCount + 1); //Expression
	}

	void visit(const ExpressionParens* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ExpressionParens");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(")\n");
	}

	void visit(const CommaExpressionStar1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "CommaExpressionStar1");
		printTabs(tabsCount+1); printf("empty\n");
	}

	void visit(const CommaExpressionStar2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "CommaExpressionStar2");
		printTabs(tabsCount+1); printf(",\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		n->e2->accept(this, tabsCount + 1); //CommaExpressionStar
	}
};
