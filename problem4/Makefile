# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGETS = cliMain serMain

all: $(TARGETS)

cliMain: cliMain.cpp
	$(CC) $(CFLAGS) -o cliMain cliMain.cpp

serMain: serMain.cpp
	$(CC) $(CFLAGS) -o serMain serMain.cpp

clean:
	rm -f $(TARGETS)

