make:
	flex lex.l
	g++ -std=c++11 lex.yy.c main.cpp
	./a.out example.txt
clean:
	rm -f lex.yy.c