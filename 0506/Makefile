GCC = g++
CFLAG = -std=c++11 -c
OFLAG = -std=c++11 -o
LIB = -pthread
EXE = online
OBJ = online.o entlea.o
${EXE}:${OBJ}
	${GCC} ${OFLAG} $@ $^ ${LIB}
%.o:%.cpp
	${GCC} ${CFLAG} $^
clean:
	rm *.o

