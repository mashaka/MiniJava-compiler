#include "visitor.hpp"

#define interface struct

interface IAbstract {
public:
	virtual void accept(IVisitor*) const = 0;
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
	Goal( IMainClass* _mainClass, IClassDeclarationStar* _classDeclarationStar ):
		mainClass(_mainClass), classDeclarationStar(_classDeclarationStar) {}

	~Goal() {
		delete mainClass;
		delete classDeclarationStar;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IMainClass* mainClass;
	IClassDeclarationStar* classDeclarationStar
};

//-----------------------------------------------------

class MainClass : public IMainClass {
	MainClass( IStatement* _statement ):
		statement(_statement) {}

	~MainClass() {
		delete statement;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IStatement* statement;
};

//-----------------------------------------------------

class ClassDeclaration1 : public IClassDeclaration {
public:
	ClassDeclaration1( IVarDeclarationStar* _varDeclarationStar, IMethodDeclarationStar* _methodDeclarationStar ):
		varDeclarationStar( _varDeclarationStar ), methodDeclarationStar(_methodDeclarationStar) {}

	~ClassDeclaration1() {
		delete varDeclarationStar;
		delete methodDeclarationStar;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}	

	IVarDeclarationStar* varDeclarationStar;
	IMethodDeclarationStar* methodDeclarationStar;
};

class ClassDeclaration2 : public IClassDeclaration {
public:
	ClassDeclaration2( IVarDeclarationStar* _varDeclarationStar, IMethodDeclarationStar* _methodDeclarationStar ):
		varDeclarationStar( _varDeclarationStar ), methodDeclarationStar(_methodDeclarationStar) {}

	~ClassDeclaration2() {
		delete varDeclarationStar;
		delete methodDeclarationStar;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IVarDeclarationStar* varDeclarationStar;
	IMethodDeclarationStar* methodDeclarationStar;
};

//-----------------------------------------------------

class ClassDeclarationStar1 : public IClassDeclarationStar {
public:
	ClassDeclarationStar1() {}

	~ClassDeclarationStar1() {}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}
};

class ClassDeclarationStar2 : public IClassDeclarationStar {
public:
	ClassDeclarationStar2( IClassDeclaration* _classDeclaration, IClassDeclarationStar* _classDeclarationStar ):
		classDeclaration( _classDeclaration ), classDeclarationStar( classDeclarationStar ) {}

	~ClassDeclarationStar2() {
		delete classDeclaration;
		delete classDeclarationStar;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IClassDeclaration* classDeclaration;
	IClassDeclarationStar* classDeclarationStar
};

//-----------------------------------------------------

class VarDeclaration : public IVarDeclaration {
public:

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

class StatementStar : public IStatement {

};

class StatementIf : public IStatement {

};

class StatementWhile : public IStatement {

};

class StatementPrint : public IStatement {

};

class StatementIdentifier1 : public IStatement {

};

class StatementIdentifier2 : public IStatement {

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
public:
    ExpressionLength( IExpression* _expression ):
        expression( _expression ) {}

    ~ExpressionLength() {
        delete expression;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
};

class ExpressionMethod : public IExpression {

};

class ExpressionEmptyMethod : public IExpression {
public:
    ExpressionEmptyMethod( IExpression* _expression ):
        expression( _expression ) {}

    ~ExpressionEmptyMethod() {
        delete expression;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
};

class ExpressionInt : public IExpression {
    ExpressionInt() {}

    ~ExpressionInt() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionTrue : public IExpression {
    ExpressionTrue() {}

    ~ExpressionTrue() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionFalse : public IExpression {
    ExpressionFalse() {}

    ~ExpressionFalse() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionId : public IExpression {
    ExpressionId() {}

    ~ExpressionId() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionThis : public IExpression {
    ExpressionThis() {}

    ~ExpressionThis() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionNew : public IExpression {
public:
    ExpressionNew( IExpression* _expression ):
        expression( _expression ) {}

    ~ExpressionNew() {
        delete expression;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
};

class ExpressionEmptyNew : public IExpression {
    ExpressionEmptyNew() {}

    ~ExpressionEmptyNew() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionNot : public IExpression {
public:
    ExpressionNot( IExpression* _expression ):
        expression( _expression ) {}

    ~ExpressionNot() {
        delete expression;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
};

class ExpressionParens : public IExpression {
public:
    ExpressionParens( IExpression* _expression ):
        expression( _expression ) {}

    ~ExpressionParens() {
        delete expression;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
};

//-----------------------------------------------------

class CommaExpressionStar1 : public ICommaExpressionStar {
    CommaExpressionStar1() {}

    ~CommaExpressionStar1() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class CommaExpressionStar2 : public ICommaExpressionStar {
public:
    CommaExpressionStar2( IExpression* _expression, ICommaExpressionStar* _commaExpressionStar ):
        expression( _expression ), commaExpressionStar( _commaExpressionStar ) {}

    ~CommaExpressionStar2() {
        delete expression;
        delete commaExpressionStar;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
    ICommaExpressionStar* commaExpressionStar;
};
