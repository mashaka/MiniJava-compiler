#include "visitor.hpp"

void printTabs(int tabsCount) {
	for(int i=0; i < tabsCount; ++i)
		printf("\t");
}

class Interpreter : public Visitor {
	void visit(const Goal* n, int tabsCount) {
		printTabs(tabsCount); 	printf("%s\n", "Goal");
		n->e1->accept(this, tabsCount + 1); //MainClass
		n->e2->accept(this, tabsCount + 1); //ClassDeclarationStar
	}
	void visit(const MainClass* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "MainClass");
		printTabs(tabsCount+1);	printf("CLASS\n");
		n->e1->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1);	printf("{\n");
		printTabs(tabsCount+1); printf("PUBLIC\n");
		printTabs(tabsCount+1); printf("STATIC\n");
		printTabs(tabsCount+1); printf("VOID\n");
		printTabs(tabsCount+1); printf("MAIN\n");
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf("STRING[]\n");
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier 
		printTabs(tabsCount+1); printf(")\n"); 
		printTabs(tabsCount+1); printf("{\n");
		n->e3->accept(this, tabsCount + 1); //Statement
		printTabs(tabsCount+1); printf("}\n");
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const ClassDeclaration1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclaration1");
		printTabs(tabsCount+1); printf("CLASS\n");
		n->e1->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1); printf("EXTENDS\n");
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1); printf("{\n");
		n->e3->accept(this, tabsCount + 1); //VarDeclarationStar
		n->e4->accept(this, tabsCount + 1); //MethodDeclarationStar
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const ClassDeclaration2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "ClassDeclaration2");
		printTabs(tabsCount+1); printf("CLASS\n", );
		n->e1->accept(this, tabsCount + 1); //TypeIdentifier
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

	void visit(const MethodDeclarationStar1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclarationStar1");
		printTabs(tabsCount+1); printf("empty\n");
	}

	void visit(const MethodDeclarationStar2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "MethodDeclarationStar2");
		n->e1->accept(this, tabsCount + 1); //MethodDeclaration
		n->e2->accept(this, tabsCount + 1); //MethodDeclarationStar
	}

	void visit(const VarDeclaration* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "VarDeclaration");
		n->e1->accept(this, tabsCount + 1); //Type
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier
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
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this, tabsCount + 1); //Type
		n->e4->accept(this, tabsCount + 1); //TypeIdentifier
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
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier
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
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier
		n->e3->accept(this, tabsCount + 1); //CommaTypeIdentifierStar
	}

	//Type 1
	void visit(const TypeIntArray* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeIntArray");
	}

	//Type 2
	void visit(const TypeBoolean* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeBoolean");
		printTabs(tabsCount+1); printf("BOOL(%s)\n", n->e1); //value
	}

	//Type 3
	void visit(const TypeInt* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeInt");
		printTabs(tabsCount+1); printf("INT(%s)\n", n->e1); //value
	}

	//Type 4
	void visit(const TypeIdentifier* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "TypeIdentifier");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //value
	}

	void visit(const Statement0* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Statement0");
		printTabs(tabsCount+1); printf("{\n");
		n->e1->accept(this, tabsCount + 1); //StatementStar
		printTabs(tabsCount+1); printf("}\n");
	}

	void visit(const Statement1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Statement1");
		printTabs(tabsCount+1); printf("if\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(")\n");
		n->e2->accept(this, tabsCount + 1); //Statement
		printTabs(tabsCount+1); printf("else\n");
		n->e3->accept(this, tabsCount + 1); //Statement
	}

	void visit(const Statement2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Statement2");
		printTabs(tabsCount+1); printf("while\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(")\n");
		n->e2->accept(this, tabsCount + 1); //Statement
	}

	void visit(const Statement3* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Statement3");
		printTabs(tabsCount+1); printf("print\n");
		printTabs(tabsCount+1); printf("(\n");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(")\n");
		printTabs(tabsCount+1); printf(";\n");
	}

	void visit(const Statement4* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Statement4");
		n->e1->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1); printf("=\n");
		n->e2->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(";\n");
	}

	void visit(const Statement5* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Statement5");
		n->e1->accept(this, tabsCount + 1); //TypeIdentifier
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

	void visit(const Expression1* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression1");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("&&\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const Expression2* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression2");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("<\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const Expression3* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression3");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("+\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const Expression4* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression4");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("-\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const Expression5* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression5");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("*\n");
		n->e2->accept(this, tabsCount + 1); //Expression
	}

	void visit(const Expression6* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression6");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("[\n");
		n->e2->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("]\n");
	}

	void visit(const Expression7* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression7");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(".\n");
		printTabs(tabsCount+1); printf("LENGTH\n");
	}

	void visit(const Expression8* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression8");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(".\n");
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1); printf("(\n");
		n->e3->accept(this, tabsCount + 1); //Expression
		n->e4->accept(this, tabsCount + 1); //CommaExpressionStar
		printTabs(tabsCount+1); printf(")\n");
	}

	void visit(const Expression9* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression9");
		n->e1->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf(".\n");
		n->e2->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
	}

	void visit(const Expression10* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression10");
		printTabs(tabsCount+1); printf("INT(%s)\n", n->e1); //value
	}

	void visit(const Expression11* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression11");
		printTabs(tabsCount+1); printf("true\n");
	}

	void visit(const Expression12* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression12");
		printTabs(tabsCount+1); printf("false\n");
	}

	void visit(const Expression13* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression13");
		printTabs(tabsCount+1); printf("ID(%s)\n", n->e1); //value
	}

	void visit(const Expression14* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression14");
		printTabs(tabsCount+1); printf("this\n");
	}

	void visit(const Expression15* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression15");
		printTabs(tabsCount+1); printf("new\n");
		n->e1->accept(this, tabsCount + 1); //TypeInt
		printTabs(tabsCount+1); printf("[\n");
		n->e2->accept(this, tabsCount + 1); //Expression
		printTabs(tabsCount+1); printf("]\n");
	}

	void visit(const Expression16* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression16");
		printTabs(tabsCount+1); printf("new\n");
		n->e1->accept(this, tabsCount + 1); //TypeIdentifier
		printTabs(tabsCount+1); printf("(\n");
		printTabs(tabsCount+1); printf(")\n");
	}

	void visit(const Expression17* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression17");
		printTabs(tabsCount+1); printf("not\n");
		n->e1->accept(this, tabsCount + 1); //Expression
	}

	void visit(const Expression18* n, int tabsCount){
		printTabs(tabsCount); 	printf("%s\n", "Expression18");
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
