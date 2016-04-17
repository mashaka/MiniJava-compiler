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
	private:
		static std::shared_ptr<Temp::TempMap> tmap;

	public:
		Tree(std::shared_ptr<Temp::TempMap> _tmap):
		tmap(_tmap)
		{}

		Tree():
		{
			tmap = std::make_shared<Temp::DefaultMap>();
		}

		Tree(std::shared_ptr<Temp::TempMap> _tmap):
		tmap(_tmap)
		{}

		Tree()
		{
			tmap = std::make_shared<Temp::DefaultMap>();
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
			print(*s, d); 
		}

		void prExp(std::shared_ptr<Exp> e, int d) {
			print(*e, d);
		}
	};
}
