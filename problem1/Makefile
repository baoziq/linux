GCC = g++
OFLAG = -o
CFLAG = -c
EXE = mycube
OBJ = mycube.o cube.o

${EXE}:${OBJ}
	${GCC} ${OFLAG} $@ $^
%.o:%.cpp
	${GCC} ${CFLAG} $^

