#pragma once

#include"IRTree.hpp"
#include"Symbol.hpp"

#include<vector>

namespace Frame {
	using namespace Temp;
	using namespace Tree;
	using namespace Symbol;


	class CFrame;
	// Переменная фрейма
	class IAccess {
	public:
		virtual Exp* getExp() = 0;
		virtual const CSymbol* getName() = 0;
		virtual ~IAccess() {}
	};

	class CFrameAccess : public IAccess {
	public:
		CFrameAccess(const CSymbol* _name, CFrame* _frame, int _offset) :
			name(_name), frame(_frame), offset(_offset) {}
		Exp* getExp();
		const CSymbol* getName() {
			return name;
		}
	private:
		const CSymbol* name;
		CFrame* frame;
		int offset;
	};

	class CRegAccess : public IAccess {
	public:
		CRegAccess(const CSymbol* _name): name(_name), temp(new Temp()) {}
		Exp* getExp();
		const CSymbol* getName() {
			return name;
		}
	private:
		const CSymbol* name;
		std::shared_ptr<Temp> temp;
	};

	class CVarAccess : public IAccess {
	public:
		CVarAccess(const CSymbol* _name, CFrame* _frame, int _offset) :
			name(_name), frame(_frame), offset(_offset) {}
		Exp* getExp();
		const CSymbol* getName() {
			return name;
		}
	private:
		const CSymbol* name;
		CFrame* frame;
		int offset;
	};

	class CFrame {
	// Класс-контейнер с платформо-зависимой информацией о функции
	public:
		static const int wordSize = 4;
		CFrame( const Symbol::CSymbol* _name):
			name(_name), localOffset(0), formalOffset(-4), framePointer(new Temp()) {
		}

		std::shared_ptr<Temp> getFP() {
			return framePointer;
		}

		std::shared_ptr<IAccess> getTP() {
			return formals[0];
		}

		std::shared_ptr<IAccess> getLocal(const CSymbol* name) {
			for (int i = 0; i < locals.size(); i++)
				if (name == locals[i]->getName())
					return locals[i];
			return 0;
		}
		std::shared_ptr<IAccess> getFormal(const CSymbol* name) {
			for (int i = 0; i < formals.size(); i++)
				if (name == formals[i]->getName())
					return formals[i];
			return 0;
		}

		std::shared_ptr<IAccess> getVar(const CSymbol* name) {
			for (int i = 0; i < vars.size(); i++)
				if (name == vars[i]->getName())
					return vars[i];
			return 0;
		}

		Exp* findByName(const CSymbol* name) {
			std::shared_ptr<IAccess> l = getLocal(name);
			std::shared_ptr<IAccess> f = getFormal(name);
			std::shared_ptr<IAccess> v = getVar(name);
			if (l!=0) return l->getExp();
			if (f!=0) return f->getExp();
			if (v!=0) return v->getExp();
			throw new std::out_of_range("Ident not found in findByName");
		}

		void allocLocal(const CSymbol* name) {
			locals.push_back(std::shared_ptr<IAccess>(new CFrameAccess(name, this, localOffset)));
			localOffset += wordSize;
		}
		void allocFormal(const CSymbol* name) {
			formals.push_back(std::shared_ptr<IAccess>(new CFrameAccess(name, this, formalOffset)));
			formalOffset -= wordSize;
		}
		void allocVar(const CSymbol* name) {
			vars.push_back(std::shared_ptr<IAccess>(new CVarAccess(name, this, varOffset)));
			varOffset += wordSize;
		}

		Exp* externalCall(const std::string& funcName, std::shared_ptr<ExpList> args) {
			return new CALL(new NAME(std::shared_ptr<Label>(new Label(funcName))), args);
		}

		~CFrame() {}
	private:
		const Symbol::CSymbol* name;
		std::shared_ptr<Temp> framePointer;
		int localOffset;
		int formalOffset;
		int varOffset;
		std::vector<std::shared_ptr<IAccess>> formals;
		std::vector<std::shared_ptr<IAccess>> locals;
		std::vector<std::shared_ptr<IAccess>> vars;

	};

	Exp* CFrameAccess::getExp() {
		return new MEM(new BINOP(ArithmeticOpType::PLUS_OP,
								 static_cast<Exp*>(new TEMP(frame->getFP())),
								 static_cast<Exp*>(new CONST(offset))));
	}

	Exp* CVarAccess::getExp() {
		return new MEM(new BINOP(ArithmeticOpType::PLUS_OP,
								 static_cast<Exp*>(new MEM(frame->getTP()->getExp())),
								 static_cast<Exp*>(new CONST(offset))));
	}

	Exp* CRegAccess::getExp() {
		return new TEMP(temp);
	}

}
