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
	IClassDeclarationStar* classDeclarationStar;
};

//-----------------------------------------------------

class VarDeclaration : public IVarDeclaration {
public:
	VarDeclaration( IType* _type ):
		type( _type ) {}

	~VarDeclaration() {
		delete type;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IType* type;
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
		varDeclarationStar( _varDeclarationStar ), varDeclaration( _varDeclaration ) {}

	~VarDeclarationStar2() {
		delete varDeclarationStar;
		delete varDeclaration;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IVarDeclarationStar* varDeclarationStar;
	IVarDeclaration* varDeclaration;
};

//-----------------------------------------------------

class MethodDeclaration1 : public IMethodDeclaration {
public:
	MethodDeclaration1( IType* _type1, IType* _type2, ICommaTypeIdentifierStar* _commaType, IVarDeclarationStar* _varDeclarationStar, IStatementStar* _statementStar, IExpression* _expression ):
		type1( _type1 ), type2( _type2 ), commaType( _commaType ), varDeclarationStar( _varDeclarationStar ), statementStar( _statementStar ), expression( _expression ) {}

	~MethodDeclaration1() {
		delete type1;
		delete type2;
		delete commaType;
		delete varDeclarationStar;
		delete statementStar;
		delete expression;
	}

	IType* type1, type2;
	ICommaTypeIdentifierStar* commaType;
	IVarDeclarationStar* varDeclarationStar;
	IStatementStar* statementStar;
	IExpression* expression;
};

class MethodDeclaration2 : public IMethodDeclaration {
public:
	MethodDeclaration2( IType* _type, IVarDeclarationStar* _varDeclarationStar, IStatementStar* _statementStar, IExpression* _expression ):
		type( _type ), varDeclarationStar( _varDeclarationStar ), statementStar( _statementStar ), expression( _expression ) {}

	~MethodDeclaration2() {
		delete type;
		delete varDeclarationStar;
		delete statementStar;
		delete expression;
	}

	IType* type;
	IVarDeclarationStar* varDeclarationStar;
	IStatementStar* statementStar;
	IExpression* expression;
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
	MethodDeclarationStar2( IMethodDeclaration* _methodDeclaration, IMethodDeclarationStar* _methodDeclarationStar ):
		methodDeclaration( _methodDeclaration ), methodDeclarationStar( _methodDeclarationStar ) {}

	~MethodDeclarationStar2() {
		delete methodDeclaration;
		delete methodDeclarationStar;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IMethodDeclaration* methodDeclaration;
	IMethodDeclarationStar* methodDeclarationStar;
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
	CommaTypeIdentifierStar2( IType* _type, ICommaTypeIdentifierStar* _commaTypeIdentifierStar ):
		type( _type ), commaTypeIdentifierStar( _commaTypeIdentifierStar ) {}

	~CommaTypeIdentifierStar2() {
		delete type;
		delete commaTypeIdentifierStar;
	}

	void accept( IVisitor* visitor ) {
		visitor->visit( this );
	}

	IType* type;
	ICommaTypeIdentifierStar* commaTypeIdentifierStar;
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
    TypeIdentifier() {}

    ~TypeIdentifier() {}

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }
};

//-----------------------------------------------------

class StatementStarBraced : public IStatement {
public:
    StatementStarBraced( IStatementStar* _statementStar ):
        statementStar( _statementStar ) {}

    ~StatementStarBraced() {
        delete statementStar;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IStatementStar* statementStar;
};

class StatementIf : public IStatement {
public:
    StatementIf( IExpression* _expression, IStatement* _statement1, IStatement* _statement2 ):
        expression( _expression ), statement1( _statement1 ), statement2( _statement2 ) {}

    ~StatementIf() {
        delete expression;
        delete statement1;
        delete statement2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
    IStatement* statement1, statement2;
};

class StatementWhile : public IStatement {
public:
    StatementWhile( IExpression* _expression, IStatement* _statement ):
        expression( _expression ), statement( _statement ) {}

    ~StatementWhile() {
        delete expression;
        delete statement;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
    IStatement* statement;
};

class StatementPrint : public IStatement {
public:
    StatementPrint( IExpression* _expression ):
        expression( _expression ) {}

    ~StatementPrint() {
        delete expression;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
};

class StatementIdentifier1 : public IStatement {
public:
    StatementIdentifier1( IExpression* _expression ):
        expression( _expression ) {}

    ~StatementIdentifier1() {
        delete expression;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression;
};

class StatementIdentifier2 : public IStatement {
public:
    StatementIdentifier2( IExpression* _expression1, IExpression* _expression2 ):
        expression1( _expression1 ), expression2( _expression2 ) {}

    ~StatementIdentifier2() {
        delete expression1;
        delete expression2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
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
        statement( _statement ), statementStar( _statementStar ) {}

    ~StatementStar2() {
        delete statement;
        delete statementStar;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IStatement* statement;
    IStatementStar* statementStar;
};

//-----------------------------------------------------

class ExpressionAndAnd : public IExpression {
public:
    ExpressionAndAnd( IExpression* _expression1, IExpression* _expression2 ):
        expression1( _expression1 ), expression2( _expression2 ) {}

    ~ExpressionAndAnd() {
        delete expression1;
        delete expression2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
};

class ExpressionLessThen : public IExpression {
public:
    ExpressionLessThen( IExpression* _expression1, IExpression* _expression2 ):
        expression1( _expression1 ), expression2( _expression2 ) {}

    ~ExpressionLessThen() {
        delete expression1;
        delete expression2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
};

class ExpressionPlus : public IExpression {
public:
    ExpressionPlus( IExpression* _expression1, IExpression* _expression2 ):
        expression1( _expression1 ), expression2( _expression2 ) {}

    ~ExpressionPlus() {
        delete expression1;
        delete expression2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
};

class ExpressionMinus : public IExpression {
public:
    ExpressionMinus( IExpression* _expression1, IExpression* _expression2 ):
        expression1( _expression1 ), expression2( _expression2 ) {}

    ~ExpressionMinus() {
        delete expression1;
        delete expression2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
};

class ExpressionMult : public IExpression {
public:
    ExpressionMult( IExpression* _expression1, IExpression* _expression2 ):
        expression1( _expression1 ), expression2( _expression2 ) {}

    ~ExpressionMult() {
        delete expression1;
        delete expression2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
};

class ExpressionBracks : public IExpression {
public:
    ExpressionBracks( IExpression* _expression1, IExpression* _expression2 ):
        expression1( _expression1 ), expression2( _expression2 ) {}

    ~ExpressionBracks() {
        delete expression1;
        delete expression2;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
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
public:
    ExpressionMethod( IExpression* _expression1, IExpression* _expression2, ICommaExpressionStar* _commaExpressionStar ):
        expression1( _expression1 ), expression2( _expression2 ), commaExpressionStar( _commaExpressionStar ) {}

    ~ExpressionMethod() {
        delete expression1;
        delete expression2;
        delete commaExpressionStar;
    }

    void accept( IVisitor* visitor ) {
        visitor->visit( this );
    }

    IExpression* expression1, expression2;
    ICommaExpressionStar* commaExpressionStar;
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
