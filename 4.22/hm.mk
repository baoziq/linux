GCC = g++
CFLAG = -c
OFLAG = -o
SEXE = serMain
SOBJ = serMain.o server.o  message.o mysem.o
CEXE = cliMain
COBJ = cliMain.o client.o  message.o mysem.o

all: ${SEXE} ${CEXE}

${SEXE}:${SOBJ}
	${GCC} ${OFLAG} $@ $^
${CEXE}:${COBJ}
	${GCC} ${OFLAG} $@ $^
%.o:%.cpp
	${GCC} ${CFLAG} $^
