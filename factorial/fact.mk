fact: fact.o func.o
	g++ -o fact fact.o func.o
fact.o: fact.cpp func.h
	g++ -c fact.cpp
func.o: func.cpp func.h
	g++ -c func.cpp


