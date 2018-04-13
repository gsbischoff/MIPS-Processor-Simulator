EXECS = main
OBJS = Main.o Parser.o ALU.o ALUControlUnit.o CPU.o ControlUnit.o DataMemory.o Multiplex.o Register.o 
CC = g++
CCFLAGS = -Wall -Wno-deprecated -Werror=return-type -g

all: $(EXECS)
	$(CC) $(CCFLAGS) $(EXECS) -o all

main: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS) 

