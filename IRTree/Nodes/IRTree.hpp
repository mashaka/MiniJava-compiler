#pragma once

#include "IRTVisitor.hpp"
#include "LabelObj.hpp"
#include "LabelList.hpp"
#include "Print.hpp"

#include <memory>


namespace Tree {
	
	class Node {
	public:
		virtual void accept(CIRVisitor* visitor) = 0;
		virtual ~Node() {}
	};

	template<class TARGET, class INTERFACE>
	class CAcceptsIRVisitor : public INTERFACE {
	public:
		virtual void accept(CIRVisitor* visitor) {
			visitor->visit( static_cast<TARGET*> (this) );
		}
	};

	//-------------------------------------------------------

	class ExpList;

	class Exp : public Node {
	public:
		virtual std::shared_ptr<ExpList> kids() = 0;
		virtual std::shared_ptr<Exp> build(std::shared_ptr<ExpList> kids) = 0;

		virtual void print(int d = 0) = 0;
	};

	//-------------------------------------------------------

	class ExpList {
	public:
		std::shared_ptr<Exp> head;
		std::shared_ptr<ExpList> tail;
		
		ExpList(std::shared_ptr<Exp> _head, std::shared_ptr<ExpList> _tail):
		head(_head), tail(_tail)
		{}
	};

	//-------------------------------------------------------

	class Stm : public std::enable_shared_from_this<Stm> { //, public Node {
	public:
		virtual std::shared_ptr<ExpList> kids() = 0;
		virtual std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) = 0;

		virtual void print(int d = 0) = 0;
	};

	//-------------------------------------------------------

	class StmList {
	public:
		std::shared_ptr<Stm> head;
		std::shared_ptr<StmList> tail;
		
		StmList(std::shared_ptr<Stm> _head, std::shared_ptr<StmList> _tail):
		head(_head),
		tail(_tail)
		{}
	};

	//-------------------------------------------------------

	class StmListList {
	public:
		std::shared_ptr<StmList> head;
		std::shared_ptr<StmListList> tail;
		
		StmListList(std::shared_ptr<StmList> _head, std::shared_ptr<StmListList> _tail):
		head(_head),
		tail(_tail)
		{}
	};

	//-------------------------------------------------------

	class Print {
	private:
		static std::shared_ptr<Temp::TempMap> tmap;

	public:
		Print()
		{
			tmap = std::make_shared<Temp::DefaultMap>();
		}

		const static std::shared_ptr<Temp::TempMap> getTmap() {
			return tmap;
		}

		static void indent(int d) {
			for(int i = 0; i < d; i++) {
				std::cout << ' ';
			}
		}

		static void say(std::string s) {
			std::cout << s;
		}

		static void sayln(std::string s) {
			std::cout << s << std::endl;
		}

		// don't need this. hallelujah to overload
		// void print(Stm s, int d=0) {}
		// void print(Exp e, int d=0) {}
		// void print(Stm s) {print(s, 0); say("\n");}
		// void print(Exp e) {print(e, 0); say("\n");}

		// for compatibility
		void prStm(std::shared_ptr<Stm> s, int d) { 
			s->print(d);
		}

		void prExp(std::shared_ptr<Exp> e, int d) {
			e->print(d);
		}
	};

	//-------------------------------------------------------

	class BINOP : public CAcceptsIRVisitor<BINOP, Exp> {
	public:
		int binop;
  		std::shared_ptr<Exp> left, right;
		static const int PLUS = 0, MINUS = 1, MUL = 2, DIV = 3, 
			AND = 4, OR = 5, LSHIFT = 6, RSHIFT = 7, ARSHIFT = 8, XOR = 9;

		BINOP(int _binop, std::shared_ptr<Exp> _left, std::shared_ptr<Exp> _right) 
			: binop(_binop), left(_left), right(_right) {}

		std::shared_ptr<ExpList> kids() override {
			return std::make_shared<ExpList>(left, std::make_shared<ExpList>(right, nullptr));
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) override {
			return std::make_shared<BINOP>(binop, _kids->head, _kids->tail->head);
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("BINOP("); 
			switch(this->binop) {
				case PLUS:    Print::say("PLUS");    break;
				case MINUS:   Print::say("MINUS");   break;
				case MUL:     Print::say("MUL");     break;
				case DIV:     Print::say("DIV");     break;
				case AND:     Print::say("AND");     break;
				case OR:      Print::say("OR");      break;
				case LSHIFT:  Print::say("LSHIFT");  break;
				case RSHIFT:  Print::say("RSHIFT");  break;
				case ARSHIFT: Print::say("ARSHIFT"); break;
				case XOR:     Print::say("XOR");     break;
				default: throw "Wrong BINOP field";
			}
			Print::sayln(",");
			this->left->print(d + 1); 
			Print::sayln(","); 
			this->right->print(d + 1); 
			Print::say(")");
		}
	};

	//-------------------------------------------------------

	class CALL : public CAcceptsIRVisitor<CALL, Exp> {
	public:
		std::shared_ptr<Exp> func;
		std::shared_ptr<ExpList> args;

		CALL(std::shared_ptr<Exp> _func, std::shared_ptr<ExpList> _args) 
			: func(_func), args(_args) {}

		std::shared_ptr<ExpList> kids() override {
			return std::make_shared<ExpList>(func, args);
		}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) override {
			return std::make_shared<CALL>(_kids->head, _kids->tail);
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("CALL(");
			this->func->print(d + 1);
			for(std::shared_ptr<ExpList> a = this->args; a != nullptr; a = a->tail) {
				Print::sayln(","); 
				a->head->print(d + 2); 
			}
			Print::say(")");
		}
	};

	//-------------------------------------------------------

	class CJUMP : public CAcceptsIRVisitor<CJUMP, Stm> {
    public:
        int relop;
        std::shared_ptr<Exp> left, right;
        std::shared_ptr<Temp::Label> iftrue, iffalse;
        static const int EQ = 0, NE = 1, LT = 2, GT = 3, LE = 4, GE = 5,
            ULT = 6, ULE = 7, UGT = 8, UGE = 9;

        CJUMP(int _relop, 
            std::shared_ptr<Exp> _left, 
            std::shared_ptr<Exp> _right, 
            std::shared_ptr<Temp::Label> _iftrue, 
            std::shared_ptr<Temp::Label> _iffalse)
            : relop(_relop), left(_left), right(_right), iftrue(_iftrue), iffalse(_iffalse) {}

        std::shared_ptr<ExpList> kids() override {
            return std::make_shared<ExpList>(left, std::make_shared<ExpList>(right, nullptr));
        }

        std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
            return std::make_shared<CJUMP>(relop, _kids->head, _kids->tail->head, iftrue, iffalse);
        }

        static int notRel(int _relop) {
            switch (_relop) {
                case EQ:  return NE;
                case NE:  return EQ;
                case LT:  return GE;
                case GE:  return LT;
                case GT:  return LE;
                case LE:  return GT;
                case ULT: return UGE;
                case UGE: return ULT;
                case UGT: return ULE;
                case ULE: return UGT;
                default:
                    std::cerr << "bad relop in CJUMP.notRel" << std::endl;
                    return -1;
            }
        }

        void print(int d = 0) override {
            Print::indent(d); 
            Print::say("CJUMP("); 
            switch(this->relop) {
                case EQ:  Print::say("EQ");  break;
                case NE:  Print::say("NE");  break;
                case LT:  Print::say("LT");  break;
                case GT:  Print::say("GT");  break;
                case LE:  Print::say("LE");  break;
                case GE:  Print::say("GE");  break;
                case ULT: Print::say("ULT"); break;
                case ULE: Print::say("ULE"); break;
                case UGT: Print::say("UGT"); break;
                case UGE: Print::say("UGE"); break;
                default: throw "Wrong CJUMP field";
            }
            Print::sayln(","); 
            this->left->print(d + 1); 
            Print::sayln(",");
            this->right->print(d + 1); 
            Print::sayln(",");
            Print::indent(d+1); 
            Print::say(this->iftrue->toString()); 
            Print::say(",");
            Print::say(this->iffalse->toString()); 
            Print::say(")");
        }
    };

    //-------------------------------------------------------

    class CONST : public CAcceptsIRVisitor<CONST, Exp> {
	public:
		int value;

		CONST(int _value) : value(_value) {}

		std::shared_ptr<ExpList> kids() override {
			return nullptr;
		}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> kids) override {
			return std::dynamic_pointer_cast<Exp>(std::make_shared<CONST>(*this));
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("CONST "); 
			Print::say(std::to_string(this->value));
		}
	};

    //-------------------------------------------------------

	class ESEQ : public CAcceptsIRVisitor<ESEQ, Exp> {
	public:
		std::shared_ptr<Stm> stm;
		std::shared_ptr<Exp> exp;

		ESEQ(std::shared_ptr<Stm> _stm, std::shared_ptr<Exp> _exp)
			: stm(_stm), exp(_exp) {}

		std::shared_ptr<ExpList> kids() override {
			std::cerr << "kids() not applicable to ESEQ" << std::endl;
			return nullptr;
		}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList>  kids) override {
			std::cerr << "build() not applicable to ESEQ" << std::endl;
			return nullptr;
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("ESEQ("); 
			this->stm->print(d + 1); 
			Print::sayln(",");
			this->exp->print(d + 1); 
			Print::say(")");
		}
	};

    //-------------------------------------------------------

	class EXP : public CAcceptsIRVisitor<EXP, Stm> {
	public:
		std::shared_ptr<Exp> exp; 

		EXP(std::shared_ptr<Exp> _exp) : exp(_exp) {}

		std::shared_ptr<ExpList> kids() override {
			return std::make_shared<ExpList>(exp, nullptr);
		}
		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
  			return std::make_shared<EXP>(_kids->head);
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("EXP("); 
			this->exp->print(d + 1); 
			Print::say(")");
		}
	};

	//-------------------------------------------------------

	class NAME : public CAcceptsIRVisitor<NAME, Exp> {
	public:
		std::shared_ptr<Temp::Label> label;

		NAME(std::shared_ptr<Temp::Label> _label):
		label(_label)
		{}

		std::shared_ptr<ExpList> kids() override {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) override {
			return std::dynamic_pointer_cast<Exp>(std::make_shared<NAME>(*this));
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("NAME "); 
			Print::say(this->label->toString());
		}
	};

    //-------------------------------------------------------

	class JUMP : public CAcceptsIRVisitor<JUMP, Stm> {
	public:
		std::shared_ptr<Exp> exp;
		std::shared_ptr<Temp::LabelList> targets;

		JUMP(std::shared_ptr<Exp> _exp, std::shared_ptr<Temp::LabelList> _targets):
		exp(_exp), targets(_targets) 
		{}

		JUMP(std::shared_ptr<Temp::Label> _target) : JUMP(std::make_shared<NAME>(_target), std::make_shared<Temp::LabelList>(_target, nullptr))
		{}

		std::shared_ptr<ExpList> kids() override {
			return std::make_shared<ExpList>(exp, nullptr);
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
			return std::make_shared<JUMP>(_kids->head, targets);
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("JUMP("); 
			this->exp->print(d + 1); 
			Print::say(")");
		}
	};

    //-------------------------------------------------------

	class LABEL : public CAcceptsIRVisitor<LABEL, Stm> {
	public:
		std::shared_ptr<Temp::Label> label;
		
		LABEL(std::shared_ptr<Temp::Label> _label):
		label(_label)
		{}

		std::shared_ptr<ExpList> kids() override {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
			return shared_from_this();
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("LABEL "); 
			Print::say(this->label->toString());
		}
	};

    //-------------------------------------------------------

    class MEM : public CAcceptsIRVisitor<MEM, Exp> {
	public:
		std::shared_ptr<Exp> exp;

		MEM(std::shared_ptr<Exp> _exp):
		exp(_exp)
		{}

		std::shared_ptr<ExpList> kids() override {
			return std::make_shared<ExpList>(exp, nullptr);
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) override {
			return std::make_shared<MEM>(_kids->head);
		}

		void print(int d = 0) override {
			Print::indent(d);
			Print::sayln("MEM("); 
			this->exp->print(d + 1); 
			Print::say(")");
		}
	};

	//-------------------------------------------------------

	class MOVE : public CAcceptsIRVisitor<MOVE, Stm> {
	public:
		std::shared_ptr<Exp> dst, src;

		MOVE(std::shared_ptr<Exp> _dst, std::shared_ptr<Exp> _src):
		dst(_dst), src(_src)
		{}

		std::shared_ptr<ExpList> kids() override {
			if (std::shared_ptr<MEM> newDst = std::dynamic_pointer_cast<MEM>(dst)) {
				return std::make_shared<ExpList>(newDst->exp, std::make_shared<ExpList>(src, nullptr));
			} else {
				return std::make_shared<ExpList>(src, nullptr);
			}
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
			if (std::dynamic_pointer_cast<MEM>(dst)) {
				return std::make_shared<MOVE>(_kids->head, _kids->tail->head);
			} else {
				return std::make_shared<MOVE>(dst, _kids->head);
			}
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("MOVE("); 
			this->dst->print(d + 1); 
			Print::sayln(",");
			this->src->print(d + 1); 
			Print::say(")");
		}
	};

	//-------------------------------------------------------

	class SEQ : public CAcceptsIRVisitor<SEQ, Stm> {
	public:
		std::shared_ptr<Stm> left, right;
		
		SEQ(std::shared_ptr<Stm> _left, std::shared_ptr<Stm> _right):
		left(_left),
		right(_right)
		{}

		std::shared_ptr<ExpList> kids() override {
			throw "kids() not applicable to SEQ";
		}

		std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) override {
			throw "kids() not applicable to SEQ";
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::sayln("SEQ("); 
			this->left->print(d + 1); 
			Print::sayln(",");
			this->right->print(d + 1); 
			Print::say(")");
		}
	};

	//-------------------------------------------------------

	class TEMP : public CAcceptsIRVisitor<TEMP, Exp> {
	public:
		std::shared_ptr<Temp::Temp> temp;

		TEMP(std::shared_ptr<Temp::Temp> _temp): temp(_temp) {}

		std::shared_ptr<ExpList> kids() override {
			// requires C++ 11 for nullptr
			return nullptr;
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) override {
			return std::dynamic_pointer_cast<Exp>(std::make_shared<TEMP>(*this));
		}

		void print(int d = 0) override {
			Print::indent(d); 
			Print::say("TEMP ");
			Print::say(Print::getTmap()->tempMap(this->temp));
		}
	};

	//-------------------------------------------------------

	class MoveCall : public CAcceptsIRVisitor<MoveCall, Stm> {
	public:
	  MoveCall(std::shared_ptr<TEMP> _destination, std::shared_ptr<CALL> _source) 
	    : destination(_destination), source(_source) {}

	  std::shared_ptr<ExpList> kids() override {
	    return source->kids();
	  }
	  std::shared_ptr<Stm> build(std::shared_ptr<ExpList> kids) override {
	    return std::make_shared<MOVE>(destination, source->build(kids));
	  }

	  void print(int d = 0) {};

	private:
	  std::shared_ptr<TEMP> destination;
	  std::shared_ptr<CALL> source;
	};

	//------------------------------------------------------------------------------------

	class ExpCall : public CAcceptsIRVisitor<ExpCall, Stm> {
	public:
	  
	  ExpCall(std::shared_ptr<CALL> _call) 
	    : call(_call) {}

	  std::shared_ptr<ExpList> kids() override {
	    return call->kids();
	  }
	  std::shared_ptr<Stm> build(std::shared_ptr<ExpList> kids) override {
	    return std::make_shared<EXP>(call->build(kids));
	  }

	  void print(int d = 0) {};

	  std::shared_ptr<CALL> call;
	};

	//------------------------------------------------------------------------------------------- 
	  
	class StmExpList {
	public:
	    StmExpList(std::shared_ptr<Stm> _stm, std::shared_ptr<ExpList> _exps)
	      : stm(_stm), exps(_exps) {}

	    std::shared_ptr<Stm> stm;
	    std::shared_ptr<ExpList> exps;
	};
}