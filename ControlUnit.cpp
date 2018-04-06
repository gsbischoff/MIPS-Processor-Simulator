#include "ControlUnit.h"
#include <string>

ControlUnit::ControlUnit()
{

}

ControlUnit::~ControlUnit()
{

}

void ControlUnit::set_datapath(std::string opcode)
{
  //if it is an R-Type
  if(opcode == "00000")
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
  else if(opcode == "100011")
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
  else if(opcode == "101011")
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
  else if("000010")
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

  /** Need to implement ADDI  ** NOT SURE ON THIS ONE **
  else if("001000")
  {
    RegDst = 0;
    ALUSrc = 0;
    MemToReg = 0;
    RegWrite = 0;
    MemRead = 0;
    MemWrite = 0;
    Branch = 0;
    ALUOp1 = 0;
    ALUOp0 = 1;
    Jump = 0;
  }
  */
  



}