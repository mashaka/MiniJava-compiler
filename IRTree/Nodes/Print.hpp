#pragma once

#include "TempMap.hpp"
#include "DefaultMap.hpp"
#include "ExpInterface.hpp"
#include "StmInterface.hpp"

#include "SEQ.hpp"
#include "LABEL.hpp"
#include "JUMP.hpp"
#include "CJUMP.hpp"
#include "MOVE.hpp"
#include "EXP.hpp"
#include "BINOP.hpp"

#include <memory>
#include <iostream>
#include <string>


namespace Tree {
	class Print {
		ostream out;
		Temp::TempMap tmap;

	public:
		Tree(std::ostream &_out, std::shared_ptr<Temp::TempMap> _tmap):
		out(_out),
		tmap(_tmap)
		{}

		Tree(std::ostream &_out):
		out(_out),
		{
			tmap = Temp::DefaultMap();
		}

		Tree(std::shared_ptr<Temp::TempMap> _tmap):
		tmap(_tmap)
		{
			out = std::cout;
		}

		Tree()
		{
			out = std::cout;
			tmap = Temp::DefaultMap();
		}

		void indent(int d) {
			for(int i = 0; i < d; i++) {
				out << ' ';
			}
		}

		void say(std::string s) {
			out << s;
		}

		void sayln(std::string s) {
			out << s << std::endl;
		}


		void print(std::shared_ptr<SEQ> s, int d=0) {
			indent(d); 
			sayln("SEQ("); 
			print(s->left, d+1); 
			sayln(",");
			print(s->right, d+1); 
			say(")");
		}

		void print(std::shared_ptr<LABEL> s, int d=0) {
			indent(d); 
			say("LABEL "); 
			say(s->label->toString());
		}

		void print(std::shared_ptr<JUMP> s, int d=0) {
			indent(d); 
			sayln("JUMP("); 
			print(s->exp, d+1); 
			say(")");
		}

		void print(std::shared_ptr<CJUMP> s, int d=0) {
			indent(d); 
			say("CJUMP("); 
			switch(s->relop) {
				case CJUMP::EQ:  say("EQ");  break;
				case CJUMP::NE:  say("NE");  break;
				case CJUMP::LT:  say("LT");  break;
				case CJUMP::GT:  say("GT");  break;
				case CJUMP::LE:  say("LE");  break;
				case CJUMP::GE:  say("GE");  break;
				case CJUMP::ULT: say("ULT"); break;
				case CJUMP::ULE: say("ULE"); break;
				case CJUMP::UGT: say("UGT"); break;
				case CJUMP::UGE: say("UGE"); break;
				default: throw "Wrong CJUMP field";
			}
			sayln(","); 
			print(s->left, d+1); 
			sayln(",");
			print(s->right, d+1); 
			sayln(",");
			indent(d+1); 
			say(s->iftrue->toString()); 
			say(",");
			say(s->iffalse->toString()); 
			say(")");
		}

		void print(std::shared_ptr<MOVE> s, int d=0) {
			indent(d); 
			sayln("MOVE("); 
			print(s->dst, d+1); 
			sayln(",");
			print(s->src, d+1); 
			say(")");
		}

		void print(std::shared_ptr<EXP> s, int d=0) {
			indent(d); 
			sayln("EXP("); 
			print(s->exp, d+1); 
			say(")");
		}

		void print(std::shared_ptr<BINOP> e, int d=0) {
			indent(d); 
			say("BINOP("); 
			switch(e->binop) {
				case BINOP::PLUS:    say("PLUS");    break;
				case BINOP::MINUS:   say("MINUS");   break;
				case BINOP::MUL:     say("MUL");     break;
				case BINOP::DIV:     say("DIV");     break;
				case BINOP::AND:     say("AND");     break;
				case BINOP::OR:      say("OR");      break;
				case BINOP::LSHIFT:  say("LSHIFT");  break;
				case BINOP::RSHIFT:  say("RSHIFT");  break;
				case BINOP::ARSHIFT: say("ARSHIFT"); break;
				case BINOP::XOR:     say("XOR");     break;
				default: throw "Wrong BINOP field";
			}
			sayln(",");
			print(e->left, d+1); 
			sayln(","); 
			print(e->right, d+1); 
			say(")");
		}

		void print(std::shared_ptr<MEM> e, int d=0) {
			indent(d);
			sayln("MEM("); 
			print(e->exp, d+1); 
			say(")");
		}

		void print(std::shared_ptr<TEMP> e, int d=0) {
			indent(d); 
			say("TEMP "); 
			say(tmap.tempMap(e.temp));
		}

		void print(std::shared_ptr<ESEQ> e, int d=0) {
			indent(d); 
			sayln("ESEQ("); 
			print(e->stm, d+1); 
			sayln(",");
			print(e->exp, d+1); 
			say(")");
		}

		void print(std::shared_ptr<NAME> e, int d=0) {
			indent(d); 
			say("NAME "); 
			say(e->label->toString());
		}

		void print(std::shared_ptr<CONST> e, int d=0) {
			indent(d); 
			say("CONST "); 
			say(std::string(e->value));
		}

		void print(std::shared_ptr<CALL> e, int d=0) {
			indent(d); 
			sayln("CALL(");
			print(e->func, d+1);
			for(std::shared_ptr<ExpList> a = e->args; a != nullptr; a = a->tail) {
				sayln(","); 
				print(a->head, d+2); 
			}
			say(")");
		}

		// don't need this. hallelujah to overload
		// void print(Stm s, int d=0) {}
		// void print(Exp e, int d=0) {}
		// void print(Stm s) {print(s, 0); say("\n");}
		// void print(Exp e) {print(e, 0); say("\n");}

		// for compatibility
		void prStm(std::shared_ptr<Stm> s, int d) { 
			print(s, d); 
		}

		void prExp(std::shared_ptr<Exp> e, int d) { 
			print(e, d); 
		}
	};
}
