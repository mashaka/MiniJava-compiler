#pragma once

#include <stdio.h>


#include "interfaces.hpp"

class IVisitor {
public:
	virtual void visit(const Goal* n, int tabsCount);
	virtual void visit(const MainClass* n, int tabsCount);

	virtual void visit(const ClassDeclaration1* n, int tabsCount);
	virtual void visit(const ClassDeclaration2* n, int tabsCount);

	virtual void visit(const ClassDeclarationStar1* n, int tabsCount);
	virtual void visit(const ClassDeclarationStar2* n, int tabsCount);

	virtual void visit(const MethodDeclarationStar1* n, int tabsCount);
	virtual void visit(const MethodDeclarationStar2* n, int tabsCount);

	virtual void visit(const VarDeclaration* n, int tabsCount);

	virtual void visit(const VarDeclarationStar1* n, int tabsCount);
	virtual void visit(const VarDeclarationStar2* n, int tabsCount);

	virtual void visit(const MethodDeclaration1* n, int tabsCount);
	virtual void visit(const MethodDeclaration2* n, int tabsCount);

	virtual void visit(const MethodDeclarationStar1* n, int tabsCount);
	virtual void visit(const MethodDeclarationStar2* n, int tabsCount);

	virtual void visit(const CommaTypeIdentifierStar1* n, int tabsCount);
	virtual void visit(const CommaTypeIdentifierStar2* n, int tabsCount);
	
	virtual void visit(const TypeIntArray* n,   int tabsCount);
	virtual void visit(const TypeBoolean* n,    int tabsCount);
	virtual void visit(const TypeInt* n,        int tabsCount);
	virtual void visit(const TypeIdentifier* n, int tabsCount);

	virtual void visit(const StatementStarBraced* n,  int tabsCount);
	virtual void visit(const StatementIf* n,          int tabsCount);
	virtual void visit(const StatementWhile* n,       int tabsCount);
	virtual void visit(const StatementPrint* n,       int tabsCount);
	virtual void visit(const StatementIdentifier1* n, int tabsCount);
	virtual void visit(const StatementIdentifier2* n, int tabsCount);

	virtual void visit(const StatementStar1* n, int tabsCount);
	virtual void visit(const StatementStar2* n, int tabsCount);

	virtual void visit(const ExpressionAndAnd* n,      int tabsCount);
	virtual void visit(const ExpressionLessThen* n,    int tabsCount);
	virtual void visit(const ExpressionPlus* n,        int tabsCount);
	virtual void visit(const ExpressionMinus* n,       int tabsCount);
	virtual void visit(const ExpressionMult* n,        int tabsCount);
	virtual void visit(const ExpressionBracks* n, 	   int tabsCount);
	virtual void visit(const ExpressionLength* n, 	   int tabsCount);
	virtual void visit(const ExpressionMethod* n, 	   int tabsCount);
	virtual void visit(const ExpressionEmptyMethod* n, int tabsCount);
	virtual void visit(const ExpressionNum* n,         int tabsCount);
	virtual void visit(const ExpressionTrue* n,        int tabsCount);
	virtual void visit(const ExpressionFalse* n,       int tabsCount);
	virtual void visit(const ExpressionId* n,          int tabsCount);
	virtual void visit(const ExpressionThis* n,        int tabsCount);
	virtual void visit(const ExpressionNew* n,         int tabsCount);
	virtual void visit(const ExpressionEmptyNew* n,    int tabsCount);
	virtual void visit(const ExpressionNot* n,         int tabsCount);
	virtual void visit(const ExpressionParens* n,      int tabsCount);

	virtual void visit(const CommaExpressionStar1* n, int tabsCount);
	virtual void visit(const CommaExpressionStar2* n, int tabsCount);
};
