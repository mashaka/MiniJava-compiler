interface IAbstract {
public:
	virtual void accept() const = 0;
}

interface IGoal : public IAbstract {
}

interface IMainClass : public IAbstract {
}

interface IClassDeclaration : public IAbstract {
}

interface IVarDeclaration : public IAbstract {
}

interface IMethodDeclaration : public IAbstract {
}

interface IType : public IAbstract {
}

interface IStatement : public IAbstract {
}

interface IExpression : public IAbstract {
}

//-----------------------------------------------------

