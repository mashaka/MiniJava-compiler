BISON=bison
FLEX=flex
CXX=g++-4.9

IDIR =./IRTree
IDIR2 =./AST
IDIR3 =./IRTree/ActivationRecords
IDIR4 =./IRTree/Nodes
IDIR5 =./IRTree/InstructionSelection
CFLAGS=-I$(IDIR) -I$(IDIR2) -I$(IDIR3) -I$(IDIR4) -I$(IDIR5) -I.

all: mini_java_compiler

syntax.tab.cc syntax.tab.hh: syntax.yy
	$(BISON) -d $<

lex.yy.c: lex.l
	$(FLEX) $<

mini_java_compiler: lex.yy.c syntax.tab.cc main.cpp
	$(CXX) -std=c++11 -fdiagnostics-color -Wno-deprecated-register $^ -o $@ $(CFLAGS)

	rm -f syntax.tab.cc syntax.tab.hh lex.yy.c syntax.output
	./mini_java_compiler examplesCambridge/Factorial.java > log.txt
