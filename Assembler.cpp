//Assembler Project1
//Camryn Carter and Jayana Turner
//Assembler c++ file
//textbook page 851

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include "Assembler.h"

using namespace std;
//constructor
//parameters: an input file used to read the asm file
//creates a Dictionary
Assembler::Assembler(string inputfile){
  filename = inputfile;

  mipsDictionary.insert({"add", "000000"});

  mipsDictionary.insert({"addi", "001000"}); //8
  mipsDictionary.insert({"sub", "000000"});
  mipsDictionary.insert({"mult", "000000"});
  mipsDictionary.insert({"div", "000000"});
  mipsDictionary.insert({"mflo", "000000"});
  mipsDictionary.insert({"mfhi", "000000"});
  mipsDictionary.insert({"sll", "000000"});
  mipsDictionary.insert({"srl", "000000"});
  mipsDictionary.insert({"lw", "0x23"});
  mipsDictionary.insert({"sw", "0x2b"});
  mipsDictionary.insert({"slt", "000000"});
  mipsDictionary.insert({"beq", "000100"});
  mipsDictionary.insert({"bne", "000101"}); //5
  mipsDictionary.insert({"j", "000010"}); //2
  mipsDictionary.insert({"jal", "000011"}); //3
  mipsDictionary.insert({"jr", "000000"});
  mipsDictionary.insert({"jalr", "000000"});
  mipsDictionary.insert({"syscall", "000000"});
   //registers for all instructions are 5 bits
   //16 8 4 2 1
  mipsDictionary.insert({"$zero", "00000"});
  mipsDictionary.insert({"$at", "00001"});
  mipsDictionary.insert({"$v0", "00010"});
  mipsDictionary.insert({"$v1", "00011"});
  mipsDictionary.insert({"$a0", "00100"});
  mipsDictionary.insert({"$a1", "00101"});
  mipsDictionary.insert({"$a2", "00110"});
  mipsDictionary.insert({"$a3", "00111"});
  mipsDictionary.insert({"t0", "01000"});
  mipsDictionary.insert({"t1", "01001"});
  mipsDictionary.insert({"t2", "01010"});
  mipsDictionary.insert({"t3", "01011"});
  mipsDictionary.insert({"t4", "01100"});
  mipsDictionary.insert({"t5", "01101"});
  mipsDictionary.insert({"t6", "01110"});
  mipsDictionary.insert({"$t7", "01111"});
  mipsDictionary.insert({"$s0", "10000"});
  mipsDictionary.insert({"$s1", "10001"});
  mipsDictionary.insert({"$s2", "10010"});
  mipsDictionary.insert({"$s3", "10011"});
  mipsDictionary.insert({"$s4", "10100"});
  mipsDictionary.insert({"$s5", "10101"});
  mipsDictionary.insert({"$s6", "10110"});
  mipsDictionary.insert({"$s7", "10111"});
  mipsDictionary.insert({"$t8", "11000"});
  mipsDictionary.insert({"$t9", "11001"});
  mipsDictionary.insert({"$k0", "11010"});
  mipsDictionary.insert({"$k1", "11011"});
  mipsDictionary.insert({"$gp", "11100"});
  mipsDictionary.insert({"$sp", "11101"});
  mipsDictionary.insert({"$fp", "11110"});
  mipsDictionary.insert({"$ra", "11111"});
  mipsDictionary.insert({"$0", "00000"});
  mipsDictionary.insert({"$1", "00001"});
  mipsDictionary.insert({"$2", "00010"});
  mipsDictionary.insert({"$3", "00011"});
  mipsDictionary.insert({"$4", "00100"});
  mipsDictionary.insert({"$5", "00101"});
  mipsDictionary.insert({"$6", "00110"});
  mipsDictionary.insert({"$7", "00111"});
  mipsDictionary.insert({"$8", "01000"});
  mipsDictionary.insert({"$9", "01001"});
  mipsDictionary.insert({"$10", "01010"});
  mipsDictionary.insert({"$11", "01011"});
  mipsDictionary.insert({"$12", "01100"});
  mipsDictionary.insert({"$13", "01101"});
  mipsDictionary.insert({"$14", "01110"});
  mipsDictionary.insert({"$15", "01111"});
  mipsDictionary.insert({"$16", "10000"});
  mipsDictionary.insert({"$17", "10001"});
  mipsDictionary.insert({"$18", "10010"});
  mipsDictionary.insert({"$19", "10011"});
  mipsDictionary.insert({"$20", "10100"});
  mipsDictionary.insert({"$21", "10101"});
  mipsDictionary.insert({"$22", "10110"});
  mipsDictionary.insert({"$23", "10111"});
  mipsDictionary.insert({"$24", "11000"});
  mipsDictionary.insert({"$25", "11001"});
  mipsDictionary.insert({"$26", "11010"});
  mipsDictionary.insert({"$27", "11011"});
  mipsDictionary.insert({"$28", "11100"});
  mipsDictionary.insert({"$29", "11101"});
  mipsDictionary.insert({"$30", "11110"});
  mipsDictionary.insert({"$31", "11111"});
}

//destuctor
Assembler::~Assembler(){
  binary.clear();
  hex.clear();
}

//convert asm instructions to its binary representation
//parameters is the string asm instruction
string instructionsToBinary(string instruction, map<string, string> mipsDictionary){
  if (mipsDictionary.count(instruction) > 0){
    string binary = mipsDictionary.at(instruction);
    return binary;
  }
  else{
    return "null";
  }
}

//coverts the asm register to its binary representation
//parameters is a string asm register
string registerToBinary(string registers, map<string, string> mipsDictionary){
  string binary = mipsDictionary.at(registers);
  return binary;
}

//converts the number to its binary representation
//parameters is a string of the number
string intToBinary(string number){
  //stoi = string t
  //valueOf() --> string
  vector<char> binaryNum;
  int num = stoi(number);
  string numbers;
  while (num >= 0){
    if (num%2 == 1){
      binaryNum.push_back('1');
      num = num -1;
      num = num/2;
    }
    else{
      binaryNum.push_back('0');
      num = num/2;
    }

    for(int i=0; i<binaryNum.size(); i++){
      numbers += binaryNum.at((binaryNum.size())-1);
    }

  }
  return numbers;
}

vector<string> split(string line, char delim){
  vector<string> asm_line;
  string section;
  char comma = ',';
  int len = line.length();
  int i = 0;
  while (i < len){
    if(line[i] == comma){
      i++;
    }
    else if(line[i]==delim){
      asm_line.push_back(section);
      i++;
      section = "";
    }
    else{
      section += line[i];
    }
  }
  return asm_line;
}

void pseudoInstructions(vector<string> mips, vector<string> binary, map<string, string> mipsDictionary){

}

//converts the asm code into binary
//parameters a vector to hold the translated binary, Dictionary to translate the asm instructions and registers to binary
//paramerers continued filename so that the method can read the asm file
//open the filename
//read line by line
//at each line we will make it a string
//send the substrings to register, instruction, int to binary
//recive the binary and put it in one section of the vector
//complete the file
//return the vector
vector<string> mipsToBinary(vector<string> binary, string filename, map<string, string> mipsDictionary){
//purple 000000 (add, sub, sll, srl, mult, div, jr, jal r, mflo, mfhi, syscall)
//green 000101 = 5 bne
//blue 000100 = 4 beq
//orange 2 and 3 j, jal
//yellow 0x23 lw
//yello ox2b sw
//addi 8
 //ofstream infile;
 ifstream infile(filename);
 string line;
 while (getline(infile, line)){
   //line would be a string that has the line of asm
   //based on the binary of the instruction send it to a method that can handel similar formats
  vector<string> asm_line;
  char delim = ' ';
  asm_line = split(line, delim);
  string instruction = asm_line.at(0);
  string instructionBinary = instructionsToBinary(instruction, mipsDictionary);
  if (instructionBinary == "000000"){
    string binaryLine = instructionBinary;

  } //if it equals 000000 (add, sub, sll, srl, mult, div, jr, jal r, mflo, mfhi, syscall)
  else if (instructionBinary == "000101") //bne
  {
    string binaryLine = instructionBinary;
    string registers = asm_line.at(1);
    string registerBinary = registerToBinary(registers, mipsDictionary);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(2);
    registerBinary = registerToBinary(register2, mipsDictionary);
    binaryLine.append(registerBinary);


    //i dont know what to do with label
    binary.push_back(binaryLine);
  }
  else if (instructionBinary == "000100") //beq
  { //we can concatenate strings or have a vector of vectors
    string binaryLine = instructionBinary;
    string registers = asm_line.at(1);
    string registerBinary = registerToBinary(registers, mipsDictionary);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(2);
    registerBinary = registerToBinary(register2, mipsDictionary);
    binaryLine.append(registerBinary);

    //do something with label
    binary.push_back(binaryLine);
  }
  else if (instructionBinary == "000010") //j
  {
    string binaryLine = instructionBinary;
    //i dont know what to do with target
  }
  else if (instructionBinary == "000011") //jal
  {
    string binaryLine = instructionBinary;

  }
  else if (instructionBinary == "001000") //addi
  {
    string binaryLine = instructionBinary;
    string register1 = asm_line.at(2);
    string registerBinary = registerToBinary(register1, mipsDictionary);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(1);
    registerBinary = registerToBinary(register2, mipsDictionary);
    binaryLine.append(registerBinary);
    string number = asm_line.at(3);
    string binaryNum = intToBinary(number);
    binaryLine.append(binaryNum);

  }
  else if (instructionBinary == "0x23") //lw
  {
    string binaryLine = instructionBinary;

  }
  else if (instructionBinary == "0x2b") //sw
  {
    string binaryLine = instructionBinary;

  }
  else{//instructionBinary == "null"
    pseudoInstructions(asm_line, binary, mipsDictionary);
  }

}
infile.close();
return binary;
}


void binaryToHex(vector<string> binary, vector<string> hex, map<string, string> mipsDictionary){

}




int main(){

}
