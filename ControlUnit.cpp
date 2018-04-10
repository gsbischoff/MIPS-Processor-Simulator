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
  if(opcode == 0)   //000000
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
  else if(opcode == 35) //"100011"
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
  else if(opcode == 43) //"101011"
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
  else if(opcode == 2) //"000010"
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

void ControlUnit::print_out()
{
  std::cout << " -------------- " << std::endl;
  std::cout << "| Control Unit |" << std::endl;
  std::cout << " -------------- " << std::endl;
  std::cout << "RegDst: " << RegDst << std::endl;
  std::cout << "ALUSrc: " << ALUSrc << std::endl;
  std::cout << "MemToReg: " << MemToReg << std::endl;
  std::cout << "RegWrite: " << RegWrite << std::endl;
  std::cout << "MemRead: " << MemRead << std::endl;
  std::cout << "MemWrite: " << MemWrite << std::endl;
  std::cout << "Branch: " << Branch << std::endl;
  std::cout << "ALUOp1: " << ALUOp1 << std::endl;
  std::cout << "ALUOp0: " << ALUOp0 << std::endl;
  std::cout << "Jump: " << Jump << std::endl;
}
