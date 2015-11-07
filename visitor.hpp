#pragma once

#include <stdio.h>
#include "interfaces.hpp"


class Goal;
class MainClass;
class ClassDeclaration1;
class ClassDeclaration2;
class ClassDeclarationStar1;
class ClassDeclarationStar2;
class MethodDeclarationStar1;
class MethodDeclarationStar2;
class VarDeclaration;
class VarDeclarationStar1;
class VarDeclarationStar2;
class MethodDeclaration1;
class MethodDeclaration2;
class MethodDeclarationStar1;
class MethodDeclarationStar2;
class CommaTypeIdentifierStar1;
class CommaTypeIdentifierStar2;
class TypeIntArray;
class TypeBoolean;
class TypeInt;
class TypeIdentifier;
class StatementStarBraced;
class StatementIf;
class StatementWhile;
class StatementPrint;
class StatementIdentifier1;
class StatementIdentifier2;
class StatementStar1;
class StatementStar2;
class ExpressionAndAnd;
class ExpressionLessThen;
class ExpressionPlus;
class ExpressionMinus;
class ExpressionMult;
class ExpressionBracks;
class ExpressionLength;
class ExpressionMethod;
class ExpressionEmptyMethod;
class ExpressionNum;
class ExpressionTrue;
class ExpressionFalse;
class ExpressionId;
class ExpressionThis;
class ExpressionNew;
class ExpressionEmptyNew;
class ExpressionNot;
class ExpressionParens;
class CommaExpressionStar1;
class CommaExpressionStar2;


class IVisitor {
public:
	virtual void visit(const Goal* n, int tabsCount) = 0;
	virtual void visit(const MainClass* n, int tabsCount) = 0;

	virtual void visit(const ClassDeclaration1* n, int tabsCount) = 0;
	virtual void visit(const ClassDeclaration2* n, int tabsCount) = 0;

	virtual void visit(const ClassDeclarationStar1* n, int tabsCount) = 0;
	virtual void visit(const ClassDeclarationStar2* n, int tabsCount) = 0;

	virtual void visit(const VarDeclaration* n, int tabsCount) = 0;

	virtual void visit(const VarDeclarationStar1* n, int tabsCount) = 0;
	virtual void visit(const VarDeclarationStar2* n, int tabsCount) = 0;

	virtual void visit(const MethodDeclaration1* n, int tabsCount) = 0;
	virtual void visit(const MethodDeclaration2* n, int tabsCount) = 0;

	virtual void visit(const MethodDeclarationStar1* n, int tabsCount) = 0;
	virtual void visit(const MethodDeclarationStar2* n, int tabsCount) = 0;

	virtual void visit(const CommaTypeIdentifierStar1* n, int tabsCount) = 0;
	virtual void visit(const CommaTypeIdentifierStar2* n, int tabsCount) = 0;

	virtual void visit(const TypeIntArray* n,   int tabsCount) = 0;
	virtual void visit(const TypeBoolean* n,    int tabsCount) = 0;
	virtual void visit(const TypeInt* n,        int tabsCount) = 0;
	virtual void visit(const TypeIdentifier* n, int tabsCount) = 0;

	virtual void visit(const StatementStarBraced* n,  int tabsCount) = 0;
	virtual void visit(const StatementIf* n,          int tabsCount) = 0;
	virtual void visit(const StatementWhile* n,       int tabsCount) = 0;
	virtual void visit(const StatementPrint* n,       int tabsCount) = 0;
	virtual void visit(const StatementIdentifier1* n, int tabsCount) = 0;
	virtual void visit(const StatementIdentifier2* n, int tabsCount) = 0;

	virtual void visit(const StatementStar1* n, int tabsCount) = 0;
	virtual void visit(const StatementStar2* n, int tabsCount) = 0;

	virtual void visit(const ExpressionAndAnd* n,      int tabsCount) = 0;
	virtual void visit(const ExpressionLessThen* n,    int tabsCount) = 0;
	virtual void visit(const ExpressionPlus* n,        int tabsCount) = 0;
	virtual void visit(const ExpressionMinus* n,       int tabsCount) = 0;
	virtual void visit(const ExpressionMult* n,        int tabsCount) = 0;
	virtual void visit(const ExpressionBracks* n, 	   int tabsCount) = 0;
	virtual void visit(const ExpressionLength* n, 	   int tabsCount) = 0;
	virtual void visit(const ExpressionMethod* n, 	   int tabsCount) = 0;
	virtual void visit(const ExpressionEmptyMethod* n, int tabsCount) = 0;
	virtual void visit(const ExpressionNum* n,         int tabsCount) = 0;
	virtual void visit(const ExpressionTrue* n,        int tabsCount) = 0;
	virtual void visit(const ExpressionFalse* n,       int tabsCount) = 0;
	virtual void visit(const ExpressionId* n,          int tabsCount) = 0;
	virtual void visit(const ExpressionThis* n,        int tabsCount) = 0;
	virtual void visit(const ExpressionNew* n,         int tabsCount) = 0;
	virtual void visit(const ExpressionEmptyNew* n,    int tabsCount) = 0;
	virtual void visit(const ExpressionNot* n,         int tabsCount) = 0;
	virtual void visit(const ExpressionParens* n,      int tabsCount) = 0;

	virtual void visit(const CommaExpressionStar1* n, int tabsCount) = 0;
	virtual void visit(const CommaExpressionStar2* n, int tabsCount) = 0;
};
