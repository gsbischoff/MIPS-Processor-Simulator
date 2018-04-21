@echo off

set EXECS= main
set OBJS= Main.cpp Parser.cpp ALU.cpp ALUControlUnit.cpp CPU.cpp ControlUnit.cpp DataMemory.cpp Multiplex.cpp Register.cpp 
set CC= g++
set LD= %CC%
set CCFLAGS= -Wall -Wno-deprecated -Werror=return-type -std=c++11 -g

%LD% %CCFLAGS% %OBJS% -o %EXECS%
