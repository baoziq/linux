GCC=g++
CFLAG=-std=c++11 -c
OFLAG=-std=c++11 -o
LIB=-pthread
SEXE=serMain
SOBJ=serMain.o server.o message.o
CEXE=cliMain
COBJ=cliMain.o client.o message.o
all:${SEXE} ${CEXE}
${SEXE}:${SOBJ}
	${GCC} ${OFLAG} $@ $^ ${LIB}
${CEXE}:${COBJ}
	${GCC} ${OFLAG} $@ $^ ${LIB}
%.0:%.cpp
	${GCC} ${CFLAG} $^

