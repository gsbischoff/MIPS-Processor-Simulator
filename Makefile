EXECS = main
OBJS = Main.o Parser.o ALU.o ALUControlUnit.o CPU.o ControlUnit.o DataMemory.o Multiplex.o Register.o 
CC = g++
LD = $(CC)
CCFLAGS = -Wall -Wno-deprecated -Werror=return-type -std=c++11 -g

all: $(EXECS)
	$(LD) $(CCFLAGS) $(OBJS) -o $(EXECS)

main: $(OBJS)
	$(LD) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS) 

