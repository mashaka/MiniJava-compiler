#pragma once

#include <stdio.h>
#include "interfaces.hpp"
#include <iostream>


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
	virtual void visit(const Goal* n) = 0;
	virtual void visit(const MainClass* n) = 0;

	virtual void visit(const ClassDeclaration1* n) = 0;
	virtual void visit(const ClassDeclaration2* n) = 0;

	virtual void visit(const ClassDeclarationList* n) = 0;

	virtual void visit(const VarDeclaration* n) = 0;

	virtual void visit(const VarDeclarationList* n) = 0;

	virtual void visit(const MethodDeclaration1* n) = 0;
	virtual void visit(const MethodDeclaration2* n) = 0;

	virtual void visit(const MethodDeclarationList* n) = 0;

	virtual void visit(const CommaTypeIdentifierList* n) = 0;

	virtual void visit(const TypeIntArray* n) = 0;
	virtual void visit(const TypeBoolean* n) = 0;
	virtual void visit(const TypeInt* n) = 0;
	virtual void visit(const TypeIdentifier* n) = 0;

	virtual void visit(const StatementListBraced* n) = 0;
	virtual void visit(const StatementIf* n) = 0;
	virtual void visit(const StatementWhile* n) = 0;
	virtual void visit(const StatementPrint* n) = 0;
	virtual void visit(const StatementIdentifier1* n) = 0;
	virtual void visit(const StatementIdentifier2* n) = 0;

	virtual void visit(const StatementList* n) = 0;

	virtual void visit(const ExpressionBinOp* n) = 0;
	virtual void visit(const ExpressionAriOp* n) = 0;
	virtual void visit(const ExpressionBracks* n) = 0;
	virtual void visit(const ExpressionLength* n) = 0;
	virtual void visit(const ExpressionMethod* n) = 0;
	virtual void visit(const ExpressionEmptyMethod* n) = 0;
	virtual void visit(const ExpressionNum* n) = 0;
	virtual void visit(const ExpressionLogOp* n) = 0;
	virtual void visit(const ExpressionId* n) = 0;
	virtual void visit(const ExpressionThis* n) = 0;
	virtual void visit(const ExpressionNew* n) = 0;
	virtual void visit(const ExpressionEmptyNew* n) = 0;
	virtual void visit(const ExpressionNot* n) = 0;
	virtual void visit(const ExpressionParens* n) = 0;

	virtual void visit(const CommaExpressionList* n) = 0;
};
