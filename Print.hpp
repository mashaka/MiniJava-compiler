#include "TempMap.hpp"
#include "DefaultMap.hpp"

#include "Label.hpp"
#include "Exp.hpp"

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

		Tree(std::ostream &_out, std::shared_ptr<Temp::TempMap> _tmap):
		out(_out),
		{
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


		void prStm(SEQ s, int d=0) {
			indent(d); sayln("SEQ("); prStm(s.left, d+1); sayln(",");
			prStm(s.right, d+1); say(")");
		}

		void prStm(LABEL s, int d=0) {
			indent(d); say("LABEL "); say(s.label.toString());
		}

		void prStm(JUMP s, int d=0) {
			indent(d); sayln("JUMP("); prExp(s.exp, d+1); say(")");
		}

		void prStm(CJUMP s, int d=0) {
			indent(d); say("CJUMP("); 
			switch(s.relop) {
				case CJUMP.EQ:  say("EQ");  break;
				case CJUMP.NE:  say("NE");  break;
				case CJUMP.LT:  say("LT");  break;
				case CJUMP.GT:  say("GT");  break;
				case CJUMP.LE:  say("LE");  break;
				case CJUMP.GE:  say("GE");  break;
				case CJUMP.ULT: say("ULT"); break;
				case CJUMP.ULE: say("ULE"); break;
				case CJUMP.UGT: say("UGT"); break;
				case CJUMP.UGE: say("UGE"); break;
				default: throw "Wrong CJUMP field";
			}
			sayln(","); prExp(s.left, d+1); sayln(",");
			prExp(s.right, d+1); sayln(",");
			indent(d+1); say(s.iftrue.toString()); say(",");
			say(s.iffalse.toString()); say(")");
		}

		void prStm(MOVE s, int d=0) {
			indent(d); sayln("MOVE("); prExp(s.dst, d+1); sayln(",");
			prExp(s.src, d+1); say(")");
		}

		void prStm(EXP s, int d=0) {
			indent(d); sayln("EXP("); prExp(s.exp, d+1); say(")");
		}

		// don't need this. hallelujah to overload
		// void prStm(Stm s, int d=0) {}

		void prExp(BINOP e, int d=0) {
			indent(d); say("BINOP("); 
			switch(e.binop) {
				case BINOP.PLUS: say("PLUS"); break;
				case BINOP.MINUS: say("MINUS"); break;
				case BINOP.MUL: say("MUL"); break;
				case BINOP.DIV: say("DIV"); break;
				case BINOP.AND: say("AND"); break;
				case BINOP.OR: say("OR"); break;
				case BINOP.LSHIFT: say("LSHIFT"); break;
				case BINOP.RSHIFT: say("RSHIFT"); break;
				case BINOP.ARSHIFT: say("ARSHIFT"); break;
				case BINOP.XOR: say("XOR"); break;
				default: throw "Wrong BINOP field";
			}
			sayln(",");
			prExp(e.left,d+1); sayln(","); prExp(e.right, d+1); say(")");
		}

		void prExp(MEM e, int d=0) {
			indent(d);
			sayln("MEM("); prExp(e.exp,d+1); say(")");
		}

		void prExp(TEMP e, int d=0) {
			indent(d); say("TEMP "); 
			say(tmap.tempMap(e.temp));
		}

		void prExp(ESEQ e, int d=0) {
			indent(d); sayln("ESEQ("); prStm(e.stm, d+1); sayln(",");
			prExp(e.exp, d+1); say(")");
		}

		void prExp(NAME e, int d=0) {
			indent(d); say("NAME "); say(e.label.toString());
		}

		void prExp(CONST e, int d=0) {
			indent(d); say("CONST "); say(String.valueOf(e.value));
		}

		void prExp(CALL e, int d=0) {
			indent(d); sayln("CALL(");
			prExp(e.func, d+1);
			// rewrite
			for(ExpList a = e.args; a!=null; a=a.tail) {
				sayln(","); prExp(a.head, d+2); 
			}
			say(")");
		}

		// don't need this. hallelujah to overload
		// void prExp(Exp e, int d=0) {}
		// void prStm(Stm s) {prStm(s, 0); say("\n");}
		// void prExp(Exp e) {prExp(e, 0); say("\n");}
	};
}
