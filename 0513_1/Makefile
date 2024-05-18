GCC = g++
CFLAG = -std=c++11 -c
OFLAG = -std=c++11 -o
LIB = -pthread
EXE = prodcons
OBJ = prodcons.o producer.o consumer.o mq.o message.o

${EXE}:${OBJ}
	${GCC} ${OFLAG} $@ $^ ${LIB}
%.o:%.cpp
	${GCC} ${CFLAG} $^
