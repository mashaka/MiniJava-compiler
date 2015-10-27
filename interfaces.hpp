//#include "visitor.cpp"

#define interface struct

interface IAbstract {
public:
	virtual void accept() const = 0;
};

interface IGoal : public IAbstract {};
interface IMainClass : public IAbstract {};
interface IClassDeclaration : public IAbstract {};
interface IClassDeclarationStar : public IAbstract {};
interface IVarDeclaration : public IAbstract {};
interface IVarDeclarationStar : public IAbstract {};
interface IMethodDeclaration : public IAbstract {};
interface IMethodDeclarationStar : public IAbstract {};
interface IType : public IAbstract {};
interface ICommaTypeIdentifierStar : public IAbstract {};
interface IStatement : public IAbstract {};
interface IStatementStar : public IAbstract {};
interface IExpression : public IAbstract {};
interface ICommaExpressionStar : public IAbstract {};

//-----------------------------------------------------

class Goal : public IGoal {

};

//-----------------------------------------------------

class MainClass : public IMainClass {

};

//-----------------------------------------------------

class ClassDeclaration1 : public IClassDeclaration {

};

class ClassDeclaration2 : public IClassDeclaration {

};

//-----------------------------------------------------

class ClassDeclarationStar1 : public IClassDeclarationStar {

};

class ClassDeclarationStar2 : public IClassDeclarationStar {

};

//-----------------------------------------------------

class VarDeclaration : public IVarDeclaration {

};

//-----------------------------------------------------

class VarDeclarationStar1 : public IVarDeclarationStar {

};

class VarDeclarationStar2 : public IVarDeclarationStar {

};

//-----------------------------------------------------

class MethodDeclaration1 : public IMethodDeclaration {

};

class MethodDeclaration2 : public IMethodDeclaration {

};

//-----------------------------------------------------

class MethodDeclarationStar1 : public IMethodDeclarationStar {

};

class MethodDeclarationStar2 : public IMethodDeclarationStar {

};

//-----------------------------------------------------

class CommaTypeIdentifierStar1 : public ICommaTypeIdentifierStar {

};

class CommaTypeIdentifierStar2 : public ICommaTypeIdentifierStar {

};

//-----------------------------------------------------

class TypeIntArray : public IType {

};

class TypeBoolean : public IType {

};

class TypeInt : public IType {

};

class TypeIdentifier : public IType {

};

//-----------------------------------------------------

class StatementIf : public IStatement {

};

class StatementWhile : public IStatement {

};

class StatementPrint : public IStatement {

};

class StatementIdentifier : public IStatement {

};

//-----------------------------------------------------

class StatementStar1 : public IStatementStar {

};

class StatementStar2 : public IStatementStar {

};

//-----------------------------------------------------

class ExpressionAndAnd : public IExpression {

};

class ExpressionLessThen : public IExpression {

};

class ExpressionPlus : public IExpression {

};

class ExpressionMinus : public IExpression {

};

class ExpressionMult : public IExpression {

};

class ExpressionBracks : public IExpression {

};

class ExpressionLength : public IExpression {

};

class ExpressionMethod : public IExpression {

};

class ExpressionEmptyMethod : public IExpression {

};

class ExpressionInt : public IExpression {

};

class ExpressionTrue : public IExpression {

};

class ExpressionFalse : public IExpression {

};

class ExpressionId : public IExpression {

};

class ExpressionThis : public IExpression {

};

class ExpressionNew : public IExpression {

};

class ExpressionEmptyNew : public IExpression {

};

class ExpressionNot : public IExpression {

};

class ExpressionParens : public IExpression {

};

//-----------------------------------------------------

class CommaExpressionStar1 : public ICommaExpressionStar {

};

class CommaExpressionStar2 : public ICommaExpressionStar {

};
