# makefile for Project 1

CC = g++
CC_FLAG = -std=c++17 -Wall -Wno-deprecated -Werror=return-type -g
OBJS = Assembler.o
EXECS = ASSEMBLE

ASSEMBLE : $(OBJS)
	$(CC) $(CC_FLAG) $^ -o $@

%.o : %.cpp *.h
	$(CC) $(CC_FLAG) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
