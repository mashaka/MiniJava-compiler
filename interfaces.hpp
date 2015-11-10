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

interface IGoal;
interface IMainClass;
interface IClassDeclaration;
interface IClassDeclarationList;
interface IVarDeclaration;
interface IVarDeclarationList;
interface IMethodDeclaration;
interface IMethodDeclarationList;
interface IType;
interface ICommaTypeIdentifierList;
interface IStatement;
interface IStatementList;
interface IExpression;
interface ICommaExpressionList;

enum ArithmeticOperator { A_PLUS, A_MINUS, A_MULT };
enum BinaryOperator { B_ANDAND, B_LT };
enum LogicalOperator { L_TRUE, L_FALSE };

//-----------------------------------------------------

class Goal : public CAcceptsVisitor<Goal, IVisitor, IGoal> {
public:
	Goal( IMainClass* _mainClass, IClassDeclarationList* _classDeclarationList ):
		e1(_mainClass), e2(_classDeclarationList) {}

	~Goal() {
		delete e1;
		delete e2;
	}

	IMainClass* e1;
	IClassDeclarationList* e2;
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
	ClassDeclaration1( char* _type1, char* _type2, IVarDeclarationList* _varDeclarationList, IMethodDeclarationList* _methodDeclarationList ):
		e1(_type1), e2(_type2), e3( _varDeclarationList ), e4(_methodDeclarationList) {}

	~ClassDeclaration1() {
		delete e1;
		delete e2;
        delete e3;
        delete e4;
	}

    char* e1, *e2;
	IVarDeclarationList* e3;
	IMethodDeclarationList* e4;
};

class ClassDeclaration2 : public CAcceptsVisitor<ClassDeclaration2, IVisitor, IClassDeclaration> {
public:
	ClassDeclaration2( char* _type, IVarDeclarationList* _varDeclarationList, IMethodDeclarationList* _methodDeclarationList ):
		e1(_type), e2( _varDeclarationList ), e3(_methodDeclarationList) {}

	~ClassDeclaration2() {
		delete e1;
		delete e2;
        delete e3;
	}

    char* e1;
	IVarDeclarationList* e2;
	IMethodDeclarationList* e3;
};

//-----------------------------------------------------

class ClassDeclarationList : public CAcceptsVisitor<ClassDeclarationList, IVisitor, IClassDeclarationList> {
public:
	ClassDeclarationList( IClassDeclaration* _classDeclaration, IClassDeclarationList* _classDeclarationList ):
		e1( _classDeclaration ), e2( _classDeclarationList ) {}

	~ClassDeclarationList() {
		delete e1;
		delete e2;
	}

	IClassDeclaration* e1;
	IClassDeclarationList* e2;
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

class VarDeclarationList : public CAcceptsVisitor<VarDeclarationList, IVisitor, IVarDeclarationList> {
public:
	VarDeclarationList( IVarDeclarationList* _varDeclarationList, IVarDeclaration* _varDeclaration ):
		e1( _varDeclarationList ), e2( _varDeclaration ) {}

	~VarDeclarationList() {
		delete e1;
		delete e2;
	}

	IVarDeclarationList* e1;
	IVarDeclaration* e2;
};

//-----------------------------------------------------

class MethodDeclaration1 : public CAcceptsVisitor<MethodDeclaration1, IVisitor, IMethodDeclaration> {
public:
	MethodDeclaration1( IType* _type1, char* _type2, IType* _type3, char* _type4, ICommaTypeIdentifierList* _commaType, IVarDeclarationList* _varDeclarationList, IStatementList* _statementList, IExpression* _expression ):
		e1( _type1 ), e2( _type2 ), e3( _type1 ), e4( _type2 ), e5( _commaType ), e6( _varDeclarationList ), e7( _statementList ), e8( _expression ) {}

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
	ICommaTypeIdentifierList* e5;
	IVarDeclarationList* e6;
	IStatementList* e7;
	IExpression* e8;
};

class MethodDeclaration2 : public CAcceptsVisitor<MethodDeclaration2, IVisitor, IMethodDeclaration> {
public:
	MethodDeclaration2( IType* _type1, char* _type2, IVarDeclarationList* _varDeclarationList, IStatementList* _statementList, IExpression* _expression ):
		e1( _type1 ), e2( _type2 ), e3( _varDeclarationList ), e4( _statementList ), e5( _expression ) {}

	~MethodDeclaration2() {
		delete e1;
		delete e2;
		delete e3;
		delete e4;
        delete e5;
	}

	IType* e1;
    char* e2;
	IVarDeclarationList* e3;
	IStatementList* e4;
	IExpression* e5;
};

//-----------------------------------------------------

class MethodDeclarationList : public CAcceptsVisitor<MethodDeclarationList, IVisitor, IMethodDeclarationList> {
public:
	MethodDeclarationList( IMethodDeclaration* _methodDeclaration, IMethodDeclarationList* _methodDeclarationList ):
		e1( _methodDeclaration ), e2( _methodDeclarationList ) {}

	~MethodDeclarationList() {
		delete e1;
		delete e2;
	}

	IMethodDeclaration* e1;
	IMethodDeclarationList* e2;
};

//-----------------------------------------------------

class CommaTypeIdentifierList : public CAcceptsVisitor<CommaTypeIdentifierList, IVisitor, ICommaTypeIdentifierList> {
public:
	CommaTypeIdentifierList( IType* _type1, char* _type2, ICommaTypeIdentifierList* _commaTypeIdentifierList ):
		e1( _type1 ), e2( _type2 ), e3( _commaTypeIdentifierList ) {}

	~CommaTypeIdentifierList() {
		delete e1;
		delete e2;
        delete e3;
	}

	IType* e1;
    char* e2;
	ICommaTypeIdentifierList* e3;
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

class StatementListBraced : public CAcceptsVisitor<StatementListBraced, IVisitor, IStatement> {
public:
    StatementListBraced( IStatementList* _statementList ):
        e1( _statementList ) {}

    ~StatementListBraced() {
        delete e1;
    }

    IStatementList* e1;
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

class StatementList : public CAcceptsVisitor<StatementList, IVisitor, IStatementList> {
public:
    StatementList( IStatement* _statement, IStatementList* _statementList ):
        e1( _statement ), e2( _statementList ) {}

    ~StatementList() {
        delete e1;
        delete e2;
    }

    IStatement* e1;
    IStatementList* e2;
};

//-----------------------------------------------------

class ExpressionBinOp : public CAcceptsVisitor<ExpressionBinOp, IVisitor, IExpression> {
public:
    ExpressionBinOp( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionBinOp() {
        delete e1;
        delete e2;
    }

    IExpression* e1, e2;
};

class ExpressionAriOp : public CAcceptsVisitor<ExpressionAriOp, IVisitor, IExpression> {
public:
    ExpressionAriOp( IExpression* _expression1, IExpression* _expression2 ):
        e1( _expression1 ), e2( _expression2 ) {}

    ~ExpressionAriOp() {
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
    ExpressionMethod( IExpression* _expression1, char* _type, IExpression* _expression2, ICommaExpressionList* _commaExpressionList ):
        e1( _expression1 ), e2( _type ), e3( _expression2 ), e4( _commaExpressionList ) {}

    ~ExpressionMethod() {
        delete e1;
        delete e2;
        delete e3;
        delete e4; 
    }

    IExpression* e1, *e3;
    char* e2;
    ICommaExpressionList* e4;
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

class ExpressionLogOp : public CAcceptsVisitor<ExpressionLogOp, IVisitor, IExpression> {
public:
    ExpressionLogOp() {}
    ~ExpressionLogOp() {}
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

class CommaExpressionList : public CAcceptsVisitor<CommaExpressionList, IVisitor, ICommaExpressionList> {
public:
    CommaExpressionList( IExpression* _expression, ICommaExpressionList* _commaExpressionList ):
        e1( _expression ), e2( _commaExpressionList ) {}

    ~CommaExpressionList() {
        delete e1;
        delete e2;
    }

    IExpression* e1;
    ICommaExpressionList* e2;
};
