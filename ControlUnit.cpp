#include "ControlUnit.h"
#include <string>
#include <iostream>

ControlUnit::ControlUnit()
{

}

ControlUnit::~ControlUnit()
{

}

void ControlUnit::set_datapath(int opcode)
{
  //if it is an R-Type
  if(opcode == 0)
  {
    RegDst = 1;
    ALUSrc = 0;
    MemToReg = 0;
    RegWrite = 1;
    MemRead = 0;
    MemWrite = 0;
    Branch = 0;
    ALUOp1 = 1;
    ALUOp0 = 0;
    Jump = 0;
  }
  //else if is it LW ?
  else if(opcode == 35)
  {
    RegDst = 0;
    ALUSrc = 1;
    MemToReg = 1;
    RegWrite = 1;
    MemRead = 1;
    MemWrite = 0;
    Branch = 0;
    ALUOp1 = 0;
    ALUOp0 = 0;
    Jump = 0;
  }
  //else if is it SW ?
  else if(opcode == 43)
  {
    RegDst = 0;
    ALUSrc = 1;
    MemToReg = 1;
    RegWrite = 0;
    MemRead = 0;
    MemWrite = 1;
    Branch = 0;
    ALUOp1 = 0;
    ALUOp0 = 0;
    Jump = 0;
  }
  //Need to implement J - TYPE ** NOT SURE ON THIS ONE **
  else if(opcode == 2)
  {
    Jump = 1;
    RegDst = 0;
    ALUSrc = 0;
    MemToReg = 0;
    RegWrite = 0;
    MemRead = 0;
    MemWrite = 0;
    Branch = 0;
    ALUOp1 = 0;
    ALUOp0 = 1;

  }
  else if(opcode == 8) //ADDI
  {
    RegDst = 0;
    ALUSrc = 1;
    MemToReg = 0;
    RegWrite = 1;
    MemRead = 0;
    MemWrite = 0;
    Branch = 0;
    ALUOp1 = 0;
    ALUOp0 = 0;
    Jump = 0;
  }
  //else it is a BEQ
  else
  {
    RegDst = 0;
    ALUSrc = 0;
    MemToReg = 0;
    RegWrite = 0;
    MemRead = 0;
    MemWrite = 0;
    Branch = 1;
    ALUOp1 = 0;
    ALUOp0 = 1;
    Jump = 0;
  }


}

void ControlUnit::print_out()
{
  std::cout << " -------------- " << std::endl;
  std::cout << "| Control Unit |" << std::endl;
  std::cout << " -------------- " << std::endl;
  printf("RegDst: 0x%x\n", RegDst);
  printf("ALUSrc: 0x%x\n", ALUSrc);
  printf("MemToReg: 0x%x\n", MemToReg);
  printf("RegWrite: 0x%x\n", RegWrite);
  printf("Memread: 0x%x\n", MemRead);
  printf("Memwrite: 0x%x\n", MemWrite);
  printf("Branch: 0x%x\n", Branch);
  printf("ALUOp1: 0x%x\n", ALUOp1);
  printf("ALUOp0: 0x%x\n", ALUOp0);
  printf("Jump: 0x%x\n\n", Jump);
}
