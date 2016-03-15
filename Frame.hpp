#include "IRTree.hpp"

namespace Frame {

// Переменная фрейма	
class IAccess {
	//хранит адрес ввиде смещения и номера переменной (? указатель на CFrame)
public:
	//возвращает соответствующий узел IRTree (предоставляет доступ к памяти)
	virtual Exp* getExp() = 0;
	virtual ~IAccess() {}
};

//---------------------------------------------------------

//доступ к переменной фрейма
class CFrameAccess : public IAccess {
public:
	CFrameAccess( CFrame* frame, int offset ) {
		this->frame = frame;
		this->offset = offset;
	}
	Exp* getExp();
private:
	CFrame* frame;
	int offset;
};

//---------------------------------------------------------

//доступ к переменной класса
class CVarAccess : public IAccess {
public:
	CVarAccess( CFrame* frame, int offset ) {
		this->frame = frame;
		this->offset = offset;
	}
	Exp* getExp();
private:
	CFrame* frame;
	int offset;
};

//---------------------------------------------------------

//доступ к регистрам
class CRegisterAccess : public IAccess {
public:
	CRegisterAccess() {}
	Exp* getExp();
private:
	CTemp temp;
};


//---------------------------------------------------------

// Класс-контейнер с платформо-зависимой информацией о функции
class CFrame {
public:
	CFrame( const Symbol::CSymbol* name, int formalsCount ) {
		this->name = name;

		this->formalsCount = formalsCount

		this->localOffset = 0;
		this->formalOffset = 0;
		this->framePointer = 0;
	}
	
	// Доступ к формальным параметрам (возвращаем количество аргументов функции)
	int FormalsCount() const { 
		return formals.size();
	}
	
	const IAccess* Formal( size_t index ) const {
		return formals[index];
	}

	const IAccess* Var( size_t index ) const {
		return formals[index];
	}

	const IAccess* Local( size_t index ) const {
		return formals[index];
	}

	void allocateFormal() {
		formals.push_back( new CFrameAccess( this, formalOffset ) );
		formalOffset -= 4;
	}

	void allocateLocal() {
		locals.push_back( new CLocalAccess( this, localOffset ) );
		localOffset -= 4;
	}

	void allocateVar() {
		vars.push_back( new CVarAccess( this, varOffset ) );
		varOffset += 4;
	}

private:
	static const int varSize = 4;

	const Symbol::CSymbol* name;
	int formalsCount;

	int localOffset;
	int formalOffset;
	int varOffset;

	std::vector<IAccess> formals; // аргументы функции
	std::vector<IAccess> locals; // локальные переменные функции
	std::vector<IAccess> vars; // переменные соответствующего класса
};

//---------------------------------------------------------

Exp* CFrameAccess::getExp(){
    return new MEM(new BINOP(ArithmeticOpType::PLUS_OP,
        static_cast<Exp*>(new TEMP(frame->getFP())),
        static_cast<Exp*>(new CONST(offset))));
}

Exp* CVarAccess::getExp(){
    return new MEM(new BINOP(ArithmeticOpType::PLUS_OP,
        static_cast<Exp*>(new MEM(frame->getTP()->getExp())),
        static_cast<Exp*>(new CONST(offset))));
}

Exp* CRegisterAccess::getExp() {
	return new IRTemp::TEMP(&temp);
}


}



