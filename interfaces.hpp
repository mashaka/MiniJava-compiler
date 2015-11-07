#pragma once

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
public:
	Goal( IMainClass* _mainClass, IClassDeclarationStar* _classDeclarationStar ):
		e1(_mainClass), e2(_classDeclarationStar) {}

	~Goal() {
		delete e1;
		delete e2;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IMainClass* e1;
	IClassDeclarationStar* e2;
};

//-----------------------------------------------------

class MainClass : public IMainClass {
public:
	MainClass( char* _type1, char* _type2, IStatement* _statement ):
		e1(_type1), e2(_type2), e3(_statement) {}

	~MainClass() {
		delete e1;
        delete e2;
        delete e3;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

    char* e1;
    char* e2;
	IStatement* e3;
};

//-----------------------------------------------------

class ClassDeclaration1 : public IClassDeclaration {
public:
	ClassDeclaration1( char* _type1, char* _type2, IVarDeclarationStar* _varDeclarationStar, IMethodDeclarationStar* _methodDeclarationStar ):
		e1(_type1), e2(_type2), e3( _varDeclarationStar ), e4(_methodDeclarationStar) {}

	~ClassDeclaration1() {
		delete e1;
		delete e2;
        delete e3;
        delete e4;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}	

    char* e1, e2;
	IVarDeclarationStar* e3;
	IMethodDeclarationStar* e4;
};

class ClassDeclaration2 : public IClassDeclaration {
public:
	ClassDeclaration2( char* _type, IVarDeclarationStar* _varDeclarationStar, IMethodDeclarationStar* _methodDeclarationStar ):
		e1(_type), e2( _varDeclarationStar ), e3(_methodDeclarationStar) {}

	~ClassDeclaration2() {
		delete e1;
		delete e2;
        delete e3;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

    char* e1;
	IVarDeclarationStar* e2;
	IMethodDeclarationStar* e3;
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
		e1( _classDeclaration ), e2( classDeclarationStar ) {}

	~ClassDeclarationStar2() {
		delete e1;
		delete e2;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IClassDeclaration* e1;
	IClassDeclarationStar* e2;
};

//-----------------------------------------------------

class VarDeclaration : public IVarDeclaration {
public:
	VarDeclaration( IType* _type1, char* _type2 ):
		e1( _type1 ), e2( _type2 ) {}

	~VarDeclaration() {
		delete e1;
        delete e2;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IType* e1;
    char* e2;
};

//-----------------------------------------------------

class VarDeclarationStar1 : public IVarDeclarationStar {
public:
	VarDeclarationStar1() {}

	~VarDeclarationStar1() {}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}
};

class VarDeclarationStar2 : public IVarDeclarationStar {
public:
	VarDeclarationStar2( IVarDeclarationStar* _varDeclarationStar, IVarDeclaration* _varDeclaration ):
		e1( _varDeclarationStar ), e2( _varDeclaration ) {}

	~VarDeclarationStar2() {
		delete e1;
		delete e2;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IVarDeclarationStar* e1;
	IVarDeclaration* e2;
};

//-----------------------------------------------------

class MethodDeclaration1 : public IMethodDeclaration {
public:
	MethodDeclaration1( IType* _type1, char* _type2, IType* _type3, char* _type4, ICommaTypeIdentifierStar* _commaType, IVarDeclarationStar* _varDeclarationStar, IStatementStar* _statementStar, IExpression* _expression ):
		e1( _type1 ), e2( _type2 ), e3( _type1 ), e4( _type2 ), e5( _commaType ), e6( _varDeclarationStar ), e7( _statementStar ), e8( _expression ) {}

	~MethodDeclaration1() {
		delete e1;
		delete e2;
        delete e3;
        delete e4;
		delete e5;
		delete e6;
		delete e7;
		delete e8;
	}

	IType* e1, e3;
    char* e2, e4;
	ICommaTypeIdentifierStar* e5;
	IVarDeclarationStar* e6;
	IStatementStar* e7;
	IExpression* e8;
};

class MethodDeclaration2 : public IMethodDeclaration {
public:
	MethodDeclaration2( IType* _type1, char* _type2, IVarDeclarationStar* _varDeclarationStar, IStatementStar* _statementStar, IExpression* _expression ):
		e1( _type1 ), e2( _type2 ), e3( _varDeclarationStar ), e4( _statementStar ), e5( _expression ) {}

	~MethodDeclaration2() {
		delete e1;
		delete e2;
		delete e3;
		delete e4;
        delete e5;
	}

	IType* e1;
    char* e2;
	IVarDeclarationStar* e3;
	IStatementStar* e4;
	IExpression* e5;
};

//-----------------------------------------------------

class MethodDeclarationStar1 : public IMethodDeclarationStar {
public:
    MethodDeclarationStar1() {}

    ~MethodDeclarationStar1() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class MethodDeclarationStar2 : public IMethodDeclarationStar {
public:
	MethodDeclarationStar2( IMethodDeclaration* _methodDeclaration, IMethodDeclarationStar* _methodDeclarationStar ):
		e1( _methodDeclaration ), e2( _methodDeclarationStar ) {}

	~MethodDeclarationStar2() {
		delete e1;
		delete e2;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IMethodDeclaration* e1;
	IMethodDeclarationStar* e2;
};

//-----------------------------------------------------

class CommaTypeIdentifierStar1 : public ICommaTypeIdentifierStar {
public:
    CommaTypeIdentifierStar1() {}

    ~CommaTypeIdentifierStar1() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class CommaTypeIdentifierStar2 : public ICommaTypeIdentifierStar {
public:
	CommaTypeIdentifierStar2( IType* _type1, char* _type2, ICommaTypeIdentifierStar* _commaTypeIdentifierStar ):
		e1( _type1 ), e2( _type2 ), e3( _commaTypeIdentifierStar ) {}

	~CommaTypeIdentifierStar2() {
		delete e1;
		delete e2;
        delete e3;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IType* e1;
    char* e2;
	ICommaTypeIdentifierStar* e3;
};

//-----------------------------------------------------

class TypeIntArray : public IType {
public:
    TypeIntArray() {}

    ~TypeIntArray() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class TypeBoolean : public IType {
public:
    TypeBoolean() {}

    ~TypeBoolean() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class TypeInt : public IType {
public:
    TypeInt() {}

    ~TypeInt() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class TypeIdentifier : public IType {
public:
    TypeIdentifier(char* _type):
        e1(_type) {}

    ~TypeIdentifier() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    char* e1;
};

//-----------------------------------------------------

class StatementStarBraced : public IStatement {
public:
    StatementStarBraced( IStatementStar* _statementStar ):
        e1( _statementStar ) {}

    ~StatementStarBraced() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IStatementStar* e1;
};

class StatementIf : public IStatement {
public:
    StatementIf( IExpression* _expression, IStatement* _statement1, IStatement* _statement2 ):
        e1( _expression ), e2( _statement1 ), e3( _statement2 ) {}

    ~StatementIf() {
        delete e1;
        delete e2;
        delete e3;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
    IStatement* e2, e3;
};

class StatementWhile : public IStatement {
public:
    StatementWhile( IExpression* _expression, IStatement* _statement ):
        e1( _expression ), e2( _statement ) {}

    ~StatementWhile() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
    IStatement* e2;
};

class StatementPrint : public IStatement {
public:
    StatementPrint( IExpression* _expression ):
        e1( _expression ) {}

    ~StatementPrint() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
};

class StatementIdentifier1 : public IStatement {
public:
    StatementIdentifier1( char* _type, IExpression* _expression ):
        e1( _type ), e2( _expression ) {}

    ~StatementIdentifier1() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    char* e1;
    IExpression* e2;
};

class StatementIdentifier2 : public IStatement {
public:
    StatementIdentifier2( char* _type, IExpression* _expression1, IExpression* _expression2 ):
        e1( _type ), e2( _expression1 ), e3( _expression2 ) {}

    ~StatementIdentifier2() {
        delete e1;
        delete e2;
        delete e3;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    char* e1
    IExpression* e2, e3;
};

//-----------------------------------------------------

class StatementStar1 : public IStatementStar {
public:
    StatementStar1() {}

    ~StatementStar1() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class StatementStar2 : public IStatementStar {
public:
    StatementStar2( IStatement* _statement, IStatementStar* _statementStar ):
        e1( _statement ), e2( _statementStar ) {}

    ~StatementStar2() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IStatement* e1;
    IStatementStar* e2;
};

//-----------------------------------------------------

class ExpressionAndAnd : public IExpression {
public:
    ExpressionAndAnd( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionAndAnd() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1, e2;
};

class ExpressionLessThen : public IExpression {
public:
    ExpressionLessThen( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionLessThen() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1, e2;
};

class ExpressionPlus : public IExpression {
public:
    ExpressionPlus( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionPlus() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1, e2;
};

class ExpressionMinus : public IExpression {
public:
    ExpressionMinus( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionMinus() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1, e2;
};

class ExpressionMult : public IExpression {
public:
    ExpressionMult( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionMult() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1, e2;
};

class ExpressionBracks : public IExpression {
public:
    ExpressionBracks( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionBracks() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1, e2;
};

class ExpressionLength : public IExpression {
public:
    ExpressionLength( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionLength() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
};

class ExpressionMethod : public IExpression {
public:
    ExpressionMethod( IExpression* _expression1, char* _type; IExpression* _expression2, ICommaExpressionStar* _commaExpressionStar ):
        e1( _expression1 ), e2( _type ), e3( _expression2 ), e4( _commaExpressionStar ) {}

    ~ExpressionMethod() {
        delete e1;
        delete e2;
        delete e3;
        delete e4; 
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1, e3;
    char* e2;
    ICommaExpressionStar* e4;
};

class ExpressionEmptyMethod : public IExpression {
public:
    ExpressionEmptyMethod( IExpression* _expression, IType* _type ):
        e1( _expression ), e2( _type ) {}

    ~ExpressionEmptyMethod() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
    IType *e2;
};

class ExpressionNum : public IExpression {
public:
    ExpressionNum(char* value):
     e1(value) {}

    ~ExpressionNum() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    char* e1;
};

class ExpressionTrue : public IExpression {
public:
    ExpressionTrue() {}

    ~ExpressionTrue() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionFalse : public IExpression {
public:
    ExpressionFalse() {}

    ~ExpressionFalse() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionId : public IExpression {
public:
    ExpressionId(char* value):
        e1(value) {}

    ~ExpressionId() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    char* e1;
};

class ExpressionThis : public IExpression {
public:
    ExpressionThis() {}

    ~ExpressionThis() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class ExpressionNew : public IExpression {
public:
    ExpressionNew( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionNew() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
};

class ExpressionEmptyNew : public IExpression {
public:
    ExpressionEmptyNew( char* _type ):
        e1( _type ) {}

    ~ExpressionEmptyNew() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    char* e1;
};

class ExpressionNot : public IExpression {
public:
    ExpressionNot( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionNot() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
};

class ExpressionParens : public IExpression {
public:
    ExpressionParens( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionParens() {
        delete e1;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
};

//-----------------------------------------------------

class CommaExpressionStar1 : public ICommaExpressionStar {
public:
    CommaExpressionStar1() {}

    ~CommaExpressionStar1() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

class CommaExpressionStar2 : public ICommaExpressionStar {
public:
    CommaExpressionStar2( IExpression* _expression, ICommaExpressionStar* _commaExpressionStar ):
        e1( _expression ), e2( _commaExpressionStar ) {}

    ~CommaExpressionStar2() {
        delete e1;
        delete e2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* e1;
    ICommaExpressionStar* e2;
};
