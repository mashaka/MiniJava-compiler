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
};
