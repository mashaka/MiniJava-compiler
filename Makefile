BISON=bison
FLEX=flex
CXX=g++

all: mini_java_compiler

visitor.o: visitor.cpp
	$(CXX) -std=c++11 $^ -o $@

syntax.tab.cc syntax.tab.hh: syntax.yy
	$(BISON) -d $<

lex.yy.c: lex.l
	$(FLEX) $<

mini_java_compiler: lex.yy.c syntax.tab.cc main.cpp
	$(CXX) -std=c++11 $^ -o $@

	rm -f syntax.tab.cc syntax.tab.hh lex.yy.c syntax.output
	./mini_java_compiler examplesCambridge/Factorial.java > log.txt
