#pragma once

#include <stdio.h>
#include "interfaces.hpp"


class Goal;
class MainClass;
class ClassDeclaration1;
class ClassDeclaration2;
class ClassDeclarationList;
class VarDeclaration;
class VarDeclarationList;
class MethodDeclaration1;
class MethodDeclaration2;
class MethodDeclarationList;
class CommaTypeIdentifierList;
class TypeIntArray;
class TypeBoolean;
class TypeInt;
class TypeIdentifier;
class StatementListBraced;
class StatementIf;
class StatementWhile;
class StatementPrint;
class StatementIdentifier1;
class StatementIdentifier2;
class StatementList;
class ExpressionBinOp;
class ExpressionAriOp;
class ExpressionBracks;
class ExpressionLength;
class ExpressionMethod;
class ExpressionEmptyMethod;
class ExpressionNum;
class ExpressionLogOp;
class ExpressionId;
class ExpressionThis;
class ExpressionNew;
class ExpressionEmptyNew;
class ExpressionNot;
class ExpressionParens;
class CommaExpressionList;


class IVisitor {
public:
	virtual void visit(const Goal* n, int tabsCount) = 0;
	virtual void visit(const MainClass* n, int tabsCount) = 0;

	virtual void visit(const ClassDeclaration1* n, int tabsCount) = 0;
	virtual void visit(const ClassDeclaration2* n, int tabsCount) = 0;

	virtual void visit(const ClassDeclarationList* n, int tabsCount) = 0;

	virtual void visit(const VarDeclaration* n, int tabsCount) = 0;

	virtual void visit(const VarDeclarationList* n, int tabsCount) = 0;

	virtual void visit(const MethodDeclaration1* n, int tabsCount) = 0;
	virtual void visit(const MethodDeclaration2* n, int tabsCount) = 0;

	virtual void visit(const MethodDeclarationList* n, int tabsCount) = 0;

	virtual void visit(const CommaTypeIdentifierList* n, int tabsCount) = 0;

	virtual void visit(const TypeIntArray* n,   int tabsCount) = 0;
	virtual void visit(const TypeBoolean* n,    int tabsCount) = 0;
	virtual void visit(const TypeInt* n,        int tabsCount) = 0;
	virtual void visit(const TypeIdentifier* n, int tabsCount) = 0;

	virtual void visit(const StatementListBraced* n,  int tabsCount) = 0;
	virtual void visit(const StatementIf* n,          int tabsCount) = 0;
	virtual void visit(const StatementWhile* n,       int tabsCount) = 0;
	virtual void visit(const StatementPrint* n,       int tabsCount) = 0;
	virtual void visit(const StatementIdentifier1* n, int tabsCount) = 0;
	virtual void visit(const StatementIdentifier2* n, int tabsCount) = 0;

	virtual void visit(const StatementList* n, int tabsCount) = 0;

	virtual void visit(const ExpressionBinOp* n,       int tabsCount) = 0;
	virtual void visit(const ExpressionAriOp* n,       int tabsCount) = 0;
	virtual void visit(const ExpressionBracks* n, 	   int tabsCount) = 0;
	virtual void visit(const ExpressionLength* n, 	   int tabsCount) = 0;
	virtual void visit(const ExpressionMethod* n, 	   int tabsCount) = 0;
	virtual void visit(const ExpressionEmptyMethod* n, int tabsCount) = 0;
	virtual void visit(const ExpressionNum* n,         int tabsCount) = 0;
	virtual void visit(const ExpressionLogOp* n,       int tabsCount) = 0;
	virtual void visit(const ExpressionId* n,          int tabsCount) = 0;
	virtual void visit(const ExpressionThis* n,        int tabsCount) = 0;
	virtual void visit(const ExpressionNew* n,         int tabsCount) = 0;
	virtual void visit(const ExpressionEmptyNew* n,    int tabsCount) = 0;
	virtual void visit(const ExpressionNot* n,         int tabsCount) = 0;
	virtual void visit(const ExpressionParens* n,      int tabsCount) = 0;

	virtual void visit(const CommaExpressionList* n, int tabsCount) = 0;
};
