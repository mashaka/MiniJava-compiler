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

class MethodDeclaration : public IMethodDeclaration {

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

class StatementStar : public IStatement {

};

class StatementIf : public IStatement {

};

class StatementWhile : public IStatement {

};

class StatementPrint : public IStatement {

};

class StatementIdentifier : public IStatement {

};
