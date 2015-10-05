BISON=bison
FLEX=flex
CXX=g++

all: mini_java_compiler

syntax.tab.cc syntax.tab.hh: syntax.yy
	$(BISON) -d $<

lex.yy.c: lex.l
	$(FLEX) $<

# add logic c++ file and others here !!!
mini_java_compiler: lex.yy.c syntax.tab.cc main.cpp
	$(CXX) -std=c++11 $^ -o $@ 


	./mini_java_compiler example.txt
	rm -f syntax.tab.cc syntax.tab.hh lex.yy.c mini_java_compiler