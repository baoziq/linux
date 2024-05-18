GCC = g++
CFLAG =-std=c++11 -c
OFLAG =-std=c++11 -o
LIB=-pthread
EXE = myprime
OBJ = myprime.o prime.o
${EXE}:${OBJ}
	${GCC} ${OFLAG} $@ $^ ${LIB}
%.o:%.cpp
	${GCC} ${CFLAG} $^

