#define interface struct

interface IAbstract {
public:
	virtual void accept() const = 0;
};

interface IGoal : public IAbstract {
};

interface IMainClass : public IAbstract {
};

interface IClassDeclaration : public IAbstract {
};

interface IVarDeclaration : public IAbstract {
};

interface IMethodDeclaration : public IAbstract {
};

interface IType : public IAbstract {
};

interface IStatement : public IAbstract {
};

interface IExpression : public IAbstract {
};

//-----------------------------------------------------

class Goal : public IGoal {

};

//-----------------------------------------------------

class MainClass : public IMainClass {

};

//-----------------------------------------------------

class ClassDeclaration : public IClassDeclaration {

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
