// IR Tree 
// Презентация 7 

#pragma once
#include "interfaces.h"
#include "Frame.hpp"

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

class CONST : public Exp {
public:
	CONST(int _value): value(_value) {}
private:
	int value;
};

class LABEL;

class NAME : public Exp {
public:
	NAME(LABEL* _label): label(_label) {}
private:
	LABEL* label;
};

class TEMP : public Exp {
public:
	TEMP(CTemp* _temp): temp(_temp) {}
private:
	CTemp* temp;
};

class BINOP : public Exp {
public:
	BINOP(EBINOP _binop, Exp* _left, Exp* _right): binop(_binop), left(_left), right(_right) {}
private:
	EBINOP binop;
	Exp *left;
	Exp *right;
};

class MEM : public Exp {
public:
	MEM(Exp* _exp): exp(_exp) {}
private:
	Exp* exp;
};

class CALL : public Exp {
public:
	CALL(Exp* _func, ExpList* _arg): func(_func), arg(_arg) {}
private:
	Exp* func;
	ExpList* arg;
};

class ESEQ : public Exp {
public:
	ESEQ(Stm* _stm, Exp* _exp): stm(_stm), exp(_exp) {}
private:
	Stm* stm;
	Exp* exp;
};

//---------------------------------------------------------------------------------------------------

class MOVE : public Stm {
public:
	MOVE(Exp* _dst, Exp* _src): dst(_dst), src(_src) {}
private:
	Exp* dst;
	Exp* src;
};

class EXP : public Stm {
public:
	EXP(Exp* _exp): exp(_exp) {}
private:
	Exp* exp;
};

class JUMP : public Stm {
public:
	JUMP(Exp* _exp, CLabel* _label): exp(_exp), label(_label) {}
private:
	Exp* exp;
	CLabel* target;
};

class CJUMP : public Stm {
public:
	CJUMP(ECJUMP _relop, Exp* _left, Exp* _right, CLabel* _iftrue, CLabel* _iffalse): relop(_relop), left(_left), right(_right), iftrue(_iftrue), iffalse(_iffalse) {}
private:
	ECJUMP relop;
	Exp* left;
	Exp* right;
	CLabel* iftrue;
	CLabel* iffalse;
};

class SEQ : public Stm {
public:
	SEQ(Stm* _left, Stm* _right): left(_left), right(_right) {}
private:
	Stm* left;
	Stm* right;
}

class LABEL : public Stm {
public:
	LABEL(CLabel* _label): label(_label) {}
private:
	CLabel* label;
}

}