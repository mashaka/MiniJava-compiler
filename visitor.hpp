#pragma once

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
	
	virtual void visit(const TypeIntArray* n, int tabsCount);
	virtual void visit(const TypeBoolean* n, int tabsCount);
	virtual void visit(const TypeInt* n, int tabsCount);
	virtual void visit(const TypeIdentifier* n, int tabsCount);

	virtual void visit(const Statement0* n, int tabsCount);
	virtual void visit(const Statement1* n, int tabsCount);
	virtual void visit(const Statement2* n, int tabsCount);
	virtual void visit(const Statement3* n, int tabsCount);
	virtual void visit(const Statement4* n, int tabsCount);
	virtual void visit(const Statement5* n, int tabsCount);

	virtual void visit(const StatementStar1* n, int tabsCount);
	virtual void visit(const StatementStar2* n, int tabsCount);

	virtual void visit(const Expression1* n, int tabsCount);
	virtual void visit(const Expression2* n, int tabsCount);
	virtual void visit(const Expression3* n, int tabsCount);
	virtual void visit(const Expression4* n, int tabsCount);
	virtual void visit(const Expression5* n, int tabsCount);
	virtual void visit(const Expression6* n, int tabsCount);
	virtual void visit(const Expression7* n, int tabsCount);
	virtual void visit(const Expression8* n, int tabsCount);
	virtual void visit(const Expression9* n, int tabsCount);
	virtual void visit(const Expression10* n, int tabsCount);
	virtual void visit(const Expression11* n, int tabsCount);
	virtual void visit(const Expression12* n, int tabsCount);
	virtual void visit(const Expression13* n, int tabsCount);
	virtual void visit(const Expression14* n, int tabsCount);
	virtual void visit(const Expression15* n, int tabsCount);
	virtual void visit(const Expression16* n, int tabsCount);
	virtual void visit(const Expression17* n, int tabsCount);
	virtual void visit(const Expression18* n, int tabsCount);

	virtual void visit(const CommaExpressionStar1* n, int tabsCount);
	virtual void visit(const CommaExpressionStar2* n, int tabsCount);
};