#pragma once

#include "visitor.hpp"

#define interface struct

template<class TARGET, class VISITOR, class INTERFACE>
class CAcceptsVisitor : public  INTERFACE {
public:
    virtual void accept(IVisitor* visit) {
        visitor->visit( static_cast<TARGET*> (this) );
    }
};

interface IGoal
interface IMainClass
interface IClassDeclaration
interface IClassDeclarationStar
interface IVarDeclaration
interface IVarDeclarationStar
interface IMethodDeclaration
interface IMethodDeclarationStar
interface IType
interface ICommaTypeIdentifierStar
interface IStatement
interface IStatementStar
interface IExpression
interface ICommaExpressionStar

enum ArithmeticOperator { A_PLUS, A_MINUS, A_MULT }
enum BinaryOperator { B_ANDAND, B_LT }
enum LogicalOperator { L_TRUE, L_FALSE }

//-----------------------------------------------------

class Goal : public CAcceptsVisitor<Goal, IVisitor, IGoal> {
public:
	Goal( IMainClass* _mainClass, IClassDeclarationStar* _classDeclarationStar ):
		e1(_mainClass), e2(_classDeclarationStar) {}

	~Goal() {
		delete e1;
		delete e2;
	}

	IMainClass* e1;
	IClassDeclarationStar* e2;
};

//-----------------------------------------------------

class MainClass : public CAcceptsVisitor<MainClass, IVisitor, IMainClass> {
public:
	MainClass( char* _type1, char* _type2, IStatement* _statement ):
		e1(_type1), e2(_type2), e3(_statement) {}

	~MainClass() {
		delete e1;
        delete e2;
        delete e3;
	}

    char* e1;
    char* e2;
	IStatement* e3;
};

//-----------------------------------------------------

class ClassDeclaration1 : public CAcceptsVisitor<ClassDeclaration1, IVisitor, IClassDeclaration> {
public:
	ClassDeclaration1( char* _type1, char* _type2, IVarDeclarationStar* _varDeclarationStar, IMethodDeclarationStar* _methodDeclarationStar ):
		e1(_type1), e2(_type2), e3( _varDeclarationStar ), e4(_methodDeclarationStar) {}

	~ClassDeclaration1() {
		delete e1;
		delete e2;
        delete e3;
        delete e4;
	}

    char* e1, *e2;
	IVarDeclarationStar* e3;
	IMethodDeclarationStar* e4;
};

class ClassDeclaration2 : public CAcceptsVisitor<ClassDeclaration2, IVisitor, IClassDeclaration> {
public:
	ClassDeclaration2( char* _type, IVarDeclarationStar* _varDeclarationStar, IMethodDeclarationStar* _methodDeclarationStar ):
		e1(_type), e2( _varDeclarationStar ), e3(_methodDeclarationStar) {}

	~ClassDeclaration2() {
		delete e1;
		delete e2;
        delete e3;
	}

    char* e1;
	IVarDeclarationStar* e2;
	IMethodDeclarationStar* e3;
};

//-----------------------------------------------------

class ClassDeclarationStar1 : public CAcceptsVisitor<ClassDeclarationStar1, IVisitor, IClassDeclarationStar> {
public:
	ClassDeclarationStar1() {}
	~ClassDeclarationStar1() {}
};

class ClassDeclarationStar2 : public CAcceptsVisitor<ClassDeclarationStar2, IVisitor, IClassDeclarationStar> {
public:
	ClassDeclarationStar2( IClassDeclaration* _classDeclaration, IClassDeclarationStar* _classDeclarationStar ):
		e1( _classDeclaration ), e2( _classDeclarationStar ) {}

	~ClassDeclarationStar2() {
		delete e1;
		delete e2;
	}

	IClassDeclaration* e1;
	IClassDeclarationStar* e2;
};

//-----------------------------------------------------

class VarDeclaration : public CAcceptsVisitor<VarDeclaration, IVisitor, IVarDeclaration> {
public:
	VarDeclaration( IType* _type1, char* _type2 ):
		e1( _type1 ), e2( _type2 ) {}

	~VarDeclaration() {
		delete e1;
        delete e2;
	}

	IType* e1;
    char* e2;
};

//-----------------------------------------------------

class VarDeclarationStar1 : public CAcceptsVisitor<VarDeclarationStar1, IVisitor, IVarDeclarationStar> {
public:
	VarDeclarationStar1() {}
	~VarDeclarationStar1() {}
};

class VarDeclarationStar2 : public CAcceptsVisitor<VarDeclarationStar2, IVisitor, IVarDeclarationStar> {
public:
	VarDeclarationStar2( IVarDeclarationStar* _varDeclarationStar, IVarDeclaration* _varDeclaration ):
		e1( _varDeclarationStar ), e2( _varDeclaration ) {}

	~VarDeclarationStar2() {
		delete e1;
		delete e2;
	}

	IVarDeclarationStar* e1;
	IVarDeclaration* e2;
};

//-----------------------------------------------------

class MethodDeclaration1 : public CAcceptsVisitor<MethodDeclaration1, IVisitor, IMethodDeclaration> {
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

	IType* e1, *e3;
    char* e2, *e4;
	ICommaTypeIdentifierStar* e5;
	IVarDeclarationStar* e6;
	IStatementStar* e7;
	IExpression* e8;
};

class MethodDeclaration2 : public CAcceptsVisitor<MethodDeclaration2, IVisitor, IMethodDeclaration> {
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

class MethodDeclarationStar1 : public CAcceptsVisitor<MethodDeclarationStar1, IVisitor, IMethodDeclarationStar> {
public:
    MethodDeclarationStar1() {}
    ~MethodDeclarationStar1() {}
};

class MethodDeclarationStar2 : public CAcceptsVisitor<MethodDeclarationStar2, IVisitor, IMethodDeclarationStar> {
public:
	MethodDeclarationStar2( IMethodDeclaration* _methodDeclaration, IMethodDeclarationStar* _methodDeclarationStar ):
		e1( _methodDeclaration ), e2( _methodDeclarationStar ) {}

	~MethodDeclarationStar2() {
		delete e1;
		delete e2;
	}

	IMethodDeclaration* e1;
	IMethodDeclarationStar* e2;
};

//-----------------------------------------------------

class CommaTypeIdentifierStar1 : public CAcceptsVisitor<CommaTypeIdentifierStar1, IVisitor, ICommaTypeIdentifierStar> {
public:
    CommaTypeIdentifierStar1() {}
    ~CommaTypeIdentifierStar1() {
};

class CommaTypeIdentifierStar2 : public CAcceptsVisitor<CommaTypeIdentifierStar2, IVisitor, ICommaTypeIdentifierStar> {
public:
	CommaTypeIdentifierStar2( IType* _type1, char* _type2, ICommaTypeIdentifierStar* _commaTypeIdentifierStar ):
		e1( _type1 ), e2( _type2 ), e3( _commaTypeIdentifierStar ) {}

	~CommaTypeIdentifierStar2() {
		delete e1;
		delete e2;
        delete e3;
	}

	IType* e1;
    char* e2;
	ICommaTypeIdentifierStar* e3;
};

//-----------------------------------------------------

class TypeIntArray : public CAcceptsVisitor<TypeIntArray, IVisitor, IType> {
public:
    TypeIntArray() {}
    ~TypeIntArray() {
};

class TypeBoolean : public CAcceptsVisitor<TypeBoolean, IVisitor, IType> {
public:
    TypeBoolean() {}
    ~TypeBoolean() {
};

class TypeInt : public CAcceptsVisitor<TypeInt, IVisitor, IType> {
public:
    TypeInt() {}
    ~TypeInt() {
};

class TypeIdentifier : public CAcceptsVisitor<TypeIdentifier, IVisitor, IType> {
public:
    TypeIdentifier(char* _type):
        e1(_type) {}

    ~TypeIdentifier() {
        delete e1;
    }

    char* e1;
};

//-----------------------------------------------------

class StatementStarBraced : public CAcceptsVisitor<StatementStarBraced, IVisitor, IStatement> {
public:
    StatementStarBraced( IStatementStar* _statementStar ):
        e1( _statementStar ) {}

    ~StatementStarBraced() {
        delete e1;
    }

    IStatementStar* e1;
};

class StatementIf : public CAcceptsVisitor<StatementIf, IVisitor, IStatement> {
public:
    StatementIf( IExpression* _expression, IStatement* _statement1, IStatement* _statement2 ):
        e1( _expression ), e2( _statement1 ), e3( _statement2 ) {}

    ~StatementIf() {
        delete e1;
        delete e2;
        delete e3;
    }

    IExpression* e1;
    IStatement* e2, e3;
};

class StatementWhile : public CAcceptsVisitor<StatementWhile, IVisitor, IStatement> {
public:
    StatementWhile( IExpression* _expression, IStatement* _statement ):
        e1( _expression ), e2( _statement ) {}

    ~StatementWhile() {
        delete e1;
        delete e2;
    }

    IExpression* e1;
    IStatement* e2;
};

class StatementPrint : public CAcceptsVisitor<StatementPrint, IVisitor, IStatement> {
public:
    StatementPrint( IExpression* _expression ):
        e1( _expression ) {}

    ~StatementPrint() {
        delete e1;
    }

    IExpression* e1;
};

class StatementIdentifier1 : public CAcceptsVisitor<StatementIdentifier1, IVisitor, IStatement> {
public:
    StatementIdentifier1( char* _type, IExpression* _expression ):
        e1( _type ), e2( _expression ) {}

    ~StatementIdentifier1() {
        delete e1;
        delete e2;
    }

    char* e1;
    IExpression* e2;
};

class StatementIdentifier2 : public CAcceptsVisitor<StatementIdentifier2, IVisitor, IStatement> {
public:
    StatementIdentifier2( char* _type, IExpression* _expression1, IExpression* _expression2 ):
        e1( _type ), e2( _expression1 ), e3( _expression2 ) {}

    ~StatementIdentifier2() {
        delete e1;
        delete e2;
        delete e3;
    }

    char* e1;
    IExpression* e2, e3;
};

//-----------------------------------------------------

class StatementStar1 : public CAcceptsVisitor<StatementStar1, IVisitor, IStatementStar> {
public:
    StatementStar1() {}
    ~StatementStar1() {}
};

class StatementStar2 : public CAcceptsVisitor<StatementStar2, IVisitor, IStatementStar> {
public:
    StatementStar2( IStatement* _statement, IStatementStar* _statementStar ):
        e1( _statement ), e2( _statementStar ) {}

    ~StatementStar2() {
        delete e1;
        delete e2;
    }

    IStatement* e1;
    IStatementStar* e2;
};

//-----------------------------------------------------

class ExpressionAndAnd : public CAcceptsVisitor<ExpressionAndAnd, IVisitor, IExpression> {
public:
    ExpressionAndAnd( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionAndAnd() {
        delete e1;
        delete e2;
    }

    IExpression* e1, e2;
};

class ExpressionLessThen : public CAcceptsVisitor<ExpressionLessThen, IVisitor, IExpression> {
public:
    ExpressionLessThen( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionLessThen() {
        delete e1;
        delete e2;
    }

    IExpression* e1, e2;
};

class ExpressionPlus : public CAcceptsVisitor<ExpressionPlus, IVisitor, IExpression> {
public:
    ExpressionPlus( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionPlus() {
        delete e1;
        delete e2;
    }

    IExpression* e1, *e2;
};

class ExpressionMinus : public CAcceptsVisitor<ExpressionMinus, IVisitor, IExpression> {
public:
    ExpressionMinus( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionMinus() {
        delete e1;
        delete e2;
    }

    IExpression* e1, *e2;
};

class ExpressionMult : public CAcceptsVisitor<ExpressionMult, IVisitor, IExpression> {
public:
    ExpressionMult( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionMult() {
        delete e1;
        delete e2;
    }

    IExpression* e1, *e2;
};

class ExpressionBracks : public CAcceptsVisitor<ExpressionBracks, IVisitor, IExpression> {
public:
    ExpressionBracks( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionBracks() {
        delete e1;
        delete e2;
    }

    IExpression* e1, *e2;
};

class ExpressionLength : public CAcceptsVisitor<ExpressionLength, IVisitor, IExpression> {
public:
    ExpressionLength( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionLength() {
        delete e1;
    }

    IExpression* e1;
};

class ExpressionMethod : public CAcceptsVisitor<ExpressionMethod, IVisitor, IExpression> {
public:
    ExpressionMethod( IExpression* _expression1, char* _type, IExpression* _expression2, ICommaExpressionStar* _commaExpressionStar ):
        e1( _expression1 ), e2( _type ), e3( _expression2 ), e4( _commaExpressionStar ) {}

    ~ExpressionMethod() {
        delete e1;
        delete e2;
        delete e3;
        delete e4; 
    }

    IExpression* e1, *e3;
    char* e2;
    ICommaExpressionStar* e4;
};

class ExpressionEmptyMethod : public CAcceptsVisitor<ExpressionEmptyMethod, IVisitor, IExpression> {
public:
    ExpressionEmptyMethod( IExpression* _expression, char* _type ):
        e1( _expression ), e2( _type ) {}

    ~ExpressionEmptyMethod() {
        delete e1;
        delete e2;
    }

    IExpression* e1;
    char *e2;
};

class ExpressionNum : public CAcceptsVisitor<ExpressionNum, IVisitor, IExpression> {
public:
    ExpressionNum(char* value):
     e1(value) {}

    ~ExpressionNum() {
        delete e1;
    }

    char* e1;
};

class ExpressionTrue : public CAcceptsVisitor<ExpressionTrue, IVisitor, IExpression> {
public:
    ExpressionTrue() {}
    ~ExpressionTrue() {}
};

class ExpressionFalse : public CAcceptsVisitor<ExpressionFalse, IVisitor, IExpression> {
public:
    ExpressionFalse() {}
    ~ExpressionFalse() {}
};

class ExpressionId : public CAcceptsVisitor<ExpressionId, IVisitor, IExpression> {
public:
    ExpressionId(char* value):
        e1(value) {}

    ~ExpressionId() {}

    char* e1;
};

class ExpressionThis : public CAcceptsVisitor<ExpressionThis, IVisitor, IExpression> {
public:
    ExpressionThis() {}

    ~ExpressionThis() {}
};

class ExpressionNew : public CAcceptsVisitor<ExpressionNew, IVisitor, IExpression> {
public:
    ExpressionNew( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionNew() {
        delete e1;
    }

    IExpression* e1;
};

class ExpressionEmptyNew : public CAcceptsVisitor<ExpressionEmptyNew, IVisitor, IExpression> {
public:
    ExpressionEmptyNew( char* _type ):
        e1( _type ) {}

    ~ExpressionEmptyNew() {
        delete e1;
    }

    char* e1;
};

class ExpressionNot : public CAcceptsVisitor<ExpressionNot, IVisitor, IExpression> {
public:
    ExpressionNot( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionNot() {
        delete e1;
    }

    IExpression* e1;
};

class ExpressionParens : public CAcceptsVisitor<ExpressionParens, IVisitor, IExpression> {
public:
    ExpressionParens( IExpression* _expression ):
        e1( _expression ) {}

    ~ExpressionParens() {
        delete e1;
    }

    IExpression* e1;
};

//-----------------------------------------------------

class CommaExpressionStar1 : public CAcceptsVisitor<CommaExpressionStar1, IVisitor, ICommaExpressionStar> {
public:
    CommaExpressionStar1() {}
    ~CommaExpressionStar1() {}
};

class CommaExpressionStar2 : public CAcceptsVisitor<CommaExpressionStar2, IVisitor, ICommaExpressionStar> {
public:
    CommaExpressionStar2( IExpression* _expression, ICommaExpressionStar* _commaExpressionStar ):
        e1( _expression ), e2( _commaExpressionStar ) {}

    ~CommaExpressionStar2() {
        delete e1;
        delete e2;
    }

    IExpression* e1;
    ICommaExpressionStar* e2;
};
