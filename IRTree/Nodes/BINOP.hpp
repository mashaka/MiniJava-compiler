#pragma once

#include "ExpInterface.hpp"
#include "ExpList.hpp"
#include "Print.hpp"

#include <memory>

namespace Tree {
	class Print;

	class BINOP : public Exp {
	public:
		int binop;
  		std::shared_ptr<Exp> left, right;
		static const int PLUS = 0, MINUS = 1, MUL = 2, DIV = 3, 
			AND = 4, OR = 5, LSHIFT = 6, RSHIFT = 7, ARSHIFT = 8, XOR = 9;

		BINOP(int _binop, std::shared_ptr<Exp> _left, std::shared_ptr<Exp> _right) 
			: binop(_binop), left(_left), right(_right) {}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(left, std::make_shared<ExpList>(right, nullptr));
		}

		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
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
}