// IR Tree 
// Презентация 7 

#pragma once
#include "interfaces.h"
#include "Frame.hpp"
#include "Temp.hpp"
#include "IRTreePrinter.hpp"


namespace IRTree 
{

// вспомогательные константы
enum ECJUMP 
{
	EQ,
	NE,
	LT,
	GT,
	LE,
	GE,
	ULT,
	UGT,
	UGE
};

enum EBINOP
{
	PLUS,
	MINUS,
	MUL,
	DIV,
	AND,
	OR,
	LSHIFT,
	RSHIFT,
	ARSHIFT,
	XOR
}

// абстракция вершины
class Node {
public:
	virtual ~Node(){}
	virtual void accept(const CIRVisitor* visitor) const = 0;
};

template<class TARGET, class INTERFACE>
class CAcceptsIRVisitor : public INTERFACE {
public:
    virtual void accept(const CIRVisitor* visitor) const {
        visitor->visit( static_cast<const TARGET*> (this) );
    }
};

// 2 основных узла
// Выражение - абстракция
class Exp : public Node {
};

// Утверждение - абстракция
class Stm : public Node {
};

// вспомогательные классы
class ExpList;

class ExpList {
public:
	ExpList(Exp* _head, ExpList* _tail): head(_head), tail(_tail) {}
private:
	Exp* head;
	ExpList* tail;
};

class StmList;

class StmList {
public:
	StmList(Stm* _head, StmList* _tail): head(_head), tail(_tail) {}
private:
	Stm* head;
	StmList* tail;
};

//---------------------------------------------------------------------------------------------------

class CONST : public CAcceptsIRVisitor<CONST, Exp> {
public:
	CONST(int _value): value(_value) {}
private:
	int value;
};

class LABEL;

class NAME : public CAcceptsIRVisitor<NAME, Exp> {
public:
	NAME(LABEL* _label): label(_label) {}
private:
	LABEL* label;
};

class TEMP : public CAcceptsIRVisitor<TEMP, Exp> {
public:
	TEMP(CTemp* _temp): temp(_temp) {}
private:
	CTemp* temp;
};

class BINOP : public CAcceptsIRVisitor<BINOP, Exp> {
public:
	BINOP(EBINOP _binop, Exp* _left, Exp* _right): binop(_binop), left(_left), right(_right) {}
private:
	EBINOP binop;
	Exp *left;
	Exp *right;
};

class MEM : public CAcceptsIRVisitor<MEM, Exp> {
public:
	MEM(Exp* _exp): exp(_exp) {}
private:
	Exp* exp;
};

class CALL : public CAcceptsIRVisitor<CALL, Exp> {
public:
	CALL(Exp* _func, ExpList* _arg): func(_func), arg(_arg) {}
private:
	Exp* func;
	ExpList* arg;
};

class ESEQ : public CAcceptsIRVisitor<ESEQ, Exp> {
public:
	ESEQ(Stm* _stm, Exp* _exp): stm(_stm), exp(_exp) {}
private:
	Stm* stm;
	Exp* exp;
};

//---------------------------------------------------------------------------------------------------

class MOVE : public CAcceptsIRVisitor<MOVE, Stm> {
public:
	MOVE(Exp* _dst, Exp* _src): dst(_dst), src(_src) {}
private:
	Exp* dst;
	Exp* src;
};

class EXP : public CAcceptsIRVisitor<EXP, Stm> {
public:
	EXP(Exp* _exp): exp(_exp) {}
private:
	Exp* exp;
};

class JUMP : public CAcceptsIRVisitor<JUMP, Stm> {
public:
	JUMP(Exp* _exp, CLabel* _label): exp(_exp), label(_label) {}
private:
	Exp* exp;
	CLabel* target;
};

class CJUMP : public CAcceptsIRVisitor<CJUMP, Stm> {
public:
	CJUMP(ECJUMP _relop, Exp* _left, Exp* _right, CLabel* _iftrue, CLabel* _iffalse): relop(_relop), left(_left), right(_right), iftrue(_iftrue), iffalse(_iffalse) {}
private:
	ECJUMP relop;
	Exp* left;
	Exp* right;
	CLabel* iftrue;
	CLabel* iffalse;
};

class SEQ : public CAcceptsIRVisitor<SEQ, Stm> {
public:
	SEQ(Stm* _left, Stm* _right): left(_left), right(_right) {}
private:
	Stm* left;
	Stm* right;
};

class LABEL : public CAcceptsIRVisitor<LABEL, Stm> {
public:
	LABEL(CLabel* _label): label(_label) {}
private:
	CLabel* label;
};

}