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
Assembler::Assembler(string inputfile, vector<string> binary, vector<string> hex){
  this->filename = inputfile;
  this->binary = binary;
  this->hex = hex;


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
  mipsDictionary.insert({"$t0", "01000"});
  mipsDictionary.insert({"$t1", "01001"});
  mipsDictionary.insert({"$t2", "01010"});
  mipsDictionary.insert({"$t3", "01011"});
  mipsDictionary.insert({"$t4", "01100"});
  mipsDictionary.insert({"$t5", "01101"});
  mipsDictionary.insert({"$t6", "01110"});
  mipsDictionary.insert({"$$t7", "01111"});
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
  mipsDictionary.insert({"0x20", "100000"});
  mipsDictionary.insert({"0x2a", "101010"});
  mipsDictionary.insert({"0x22", "100010"});
  mipsDictionary.insert({"0x12", "010010"});
  mipsDictionary.insert({"0x10", "010000"});
  mipsDictionary.insert({"0x1a", "011010"});
  mipsDictionary.insert({"0x18", "011000"});
  mipsDictionary.insert({"0x23", "100011"});
  mipsDictionary.insert({"0x2b", "101011"});
  mipsDictionary.insert({"0000", "0"});
  mipsDictionary.insert({"0001", "1"});
  mipsDictionary.insert({"0010", "2"});
  mipsDictionary.insert({"0011", "3"});
  mipsDictionary.insert({"0100", "4"});
  mipsDictionary.insert({"0101", "5"});
  mipsDictionary.insert({"0110", "6"});
  mipsDictionary.insert({"0111", "7"});
  mipsDictionary.insert({"1000", "8"});
  mipsDictionary.insert({"1001", "9"});
  mipsDictionary.insert({"1010", "A"});
  mipsDictionary.insert({"1011", "B"});
  mipsDictionary.insert({"1100", "C"});
  mipsDictionary.insert({"1101", "D"});
  mipsDictionary.insert({"1110", "E"});
  mipsDictionary.insert({"1111", "F"});



  //this->binary.push_back("null");
  //hex.push_back("null");
}

//destuctor
Assembler::~Assembler(){
  binary.clear();
  hex.clear();
}

vector<string> Assembler::getBinary(){
  return this->binary;
}

//convert asm instructions to its binary representation
//parameters is the string asm instruction
string Assembler::instructionsToBinary(string instruction, map<string, string> mipsDictionary){
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
string Assembler::registerToBinary(string registers, map<string, string> mipsDictionary){
  //cout << "register =" << registers <<"length" << registers.length()<< endl;
  string binary = mipsDictionary[registers];
  //cout << "string = " << binary << " length " << binary.length() << endl;
  return binary;
}

//converts the number to its binary representation
//parameters is a string of the number
string Assembler::intToBinary(string immediate){
  //stoi = string t
  //valueOf() --> string
//  cout << "int to binary" <<endl;
  vector<char> binaryNum;
  int num = stoi(immediate);
  //cout << num << endl;
  int og_num = num;
  string numbers;
//  cout << "before if" << endl;

  if (num < 0){
    num = num * -1;
  }
//  cout << "before while" << endl;

  while (num > 0){
    if (num%2 == 1){
    //  cout << num << endl;
      binaryNum.push_back('1');
      num = num - 1;
      num = num/2;
      //cout << "in if after" << endl;

    }
    else{
    //  cout << num << endl;

      binaryNum.push_back('0');
      num = num/2;
      //cout << "in else after" << endl;
    }
  }
  //cout << "after while" << endl;
  for (int j = binaryNum.size(); j<16; j++){
    numbers += "0";
  }
  for(int i=1; i<=binaryNum.size(); i++){
    numbers += binaryNum.at((binaryNum.size())-i);
  }
//  cout << "close to end" << endl;
  if (og_num < 0){
    //cout << "should not be here" << endl;
    vector<char> negativeNum;
    string inverse = "";
    string one = "0000000000000001";
    for(int x=0; x<numbers.length() ; x++){
        if (numbers.substr(x,1) == "0"){
          inverse += "1";
        }
        else{
          inverse += "0";
        }
    }
    char carry ='0';
    for(int y=one.length()-1; y<=0; y--){
      if(inverse.substr(y,1)=="0" && one.substr(y,1)=="0" && carry == '0'){
        negativeNum.push_back('0');
      }
      else if(inverse.substr(y,1)=="0" && one.substr(y,1)=="0" && carry == '1'){
        negativeNum.push_back('1');
      }
      else if(inverse.substr(y,1)=="1" && one.substr(y,1)=="0" && carry == '0'){
        negativeNum.push_back('1');
      }
      else if(inverse.substr(y,1)=="0" && one.substr(y,1)=="1" && carry == '0'){
        negativeNum.push_back('1');
      }
      else if(inverse.substr(y,1)=="1" && one.substr(y,1)=="1" && carry == '0'){
        negativeNum.push_back('0');
        carry = '1';
      }
      else if(inverse.substr(y,1)=="1" && one.substr(y,1)=="0" && carry == '1'){
        negativeNum.push_back('0');
        carry = '1';
      }
      else if(inverse.substr(y,1)=="0" && one.substr(y,1)=="1" && carry == '1'){
        negativeNum.push_back('0');
        carry = '1';
      }
      else{
        negativeNum.push_back('1');
        carry = '1';
      }
    }
    numbers = "";
    for(int i=0; i<negativeNum.size(); i++){
      numbers += negativeNum.at((negativeNum.size())-i);
      cout << numbers << " negative" << endl;
    }
    return numbers;
  }
  else{
  //  cout << "out of int to binary" <<endl;
    return numbers;

  }
}

//splits a string based on the seperator given and also ignores commas
//parameters string and a char deliminator
//returns a vector containing the seperated string
vector<string> Assembler::split(string line){

  char delim = ' ';
  vector<string> words;
  size_t pos = 0;
  string lineCopy;

  // removes commas and comments from the line
  int i = 0;
  while(i < line.length()){
    //cout<< "while1" << endl;

    if(line[i] == '#'){
      break;
    }
    if(line[i] != ','){
      if(line[i] == ' ' && i == line.length()-1){
          break;
        }
        else{
          lineCopy += line[i];
        }
      }

      i++;
    }

// seperates the line by whitespace
 pos = lineCopy.find(delim);
  while(pos != -1){
    //cout<< "while" << endl;
    words.push_back(lineCopy.substr(0,pos));
    lineCopy.erase(0, pos + 1);
    pos = lineCopy.find(delim);
  }
  words.push_back(lineCopy.substr(0,pos));


  // gets rid of extra spaces at the end of line
  string temp = words.at(words.size()-1);
  if(temp == ""){
    words.pop_back();
  }
  /*
  if(temp.at(temp.length()-1) == ' '){
    temp.erase(temp.length()-1);
    words.pop_back();
    words.push_back(temp);
  }*/

  for(int x =0; x < words.size(); x++){

      cout << words.at(x) << endl;
  }



//  cout << words.at(words.size()-1) << "size:"<<(words.at(words.size()-1)).size() << endl;
//  cout << (words.at(words.size()-1)).length() << endl;


  return words;
}

void Assembler::pseudoInstructions(vector<string> mips, vector<string> binary, map<string, string> mipsDictionary){

}

// the asm code into binary
//parameters a vector to hold the translated binary, Dictionary to translate the asm instructions and registers to binary
//paramerers continued filename so that the method can read the asm file
//open the filename
//read line by line
//at each line we will make it a string
//send the substrings to register, instruction, int to binary
//recive the binary and put it in one section of the vector
//complete the file
//return the vector
vector<string> Assembler::mipsToBinary(){
//purple 000000 (add, sub, sll, srl, mult, div, jr, jal r, mflo, mfhi, syscall)
//green 000101 = 5 bne
//blue 000100 = 4 beq
//orange 2 and 3 j, jal
//yellow 0x23 lw
//yello ox2b sw
//addi 8
 //ofstream infile;
// cout << "in mips to binary" <<endl;
 ifstream infile(filename);
 string line;
 while (getline(infile, line)){
   //line would be a string that has the line of asm
   //based on the binary of the instruction send it to a method that can handel similar formats
   //cout<< line << endl;
  vector<string> asm_line;
  char delim = ' ';
  asm_line = split(line);
  string instruction = asm_line.at(0);
//  cout << asm_line.at(0) << endl;
  //cout << asm_line.at(1) << endl;
  //cout << asm_line.at(2) << endl;
  //cout << asm_line.at(3) << endl;

  string instructionBinary = instructionsToBinary(instruction, mipsDictionary);
  if (instructionBinary == "000000"){
    string binaryLine = instructionBinary;
    if (instruction == "add" || instruction == "sub" || instruction == "slt"){
    //  cout << instructionBinary <<endl;
      string registers = asm_line.at(2);
      //cout << registers <<endl;
      string registerBinary = registerToBinary(registers, mipsDictionary);
      //cout << registerBinary <<endl;
      binaryLine.append(registerBinary);
      registers = asm_line.at(3);
      //cout << "number 3 " << registers <<endl;
      registerBinary = registerToBinary(registers, mipsDictionary);
      //cout << "number 3 " << registerBinary <<endl;
      binaryLine.append(registerBinary);
      registers = asm_line.at(1);
      //cout << registers <<endl;
      registerBinary = registerToBinary(registers, mipsDictionary);
      //cout << registerBinary <<endl;
      binaryLine.append(registerBinary);
      //cout << instructionBinary <<endl;
      binaryLine.append("00000");
      //cout << instructionBinary <<endl;
      if(instruction == "add"){
        registerBinary = mipsDictionary["0x20"];
        binaryLine.append(registerBinary);

      }
      else if(instruction == "slt"){
        registerBinary = mipsDictionary["0x2a"];
        binaryLine.append(registerBinary);
      }
      else{
        registerBinary = mipsDictionary["0x22"];
        binaryLine.append(registerBinary);
        //add 0x21
      }
      binary.push_back(binaryLine);
      //cout << "end of add" <<endl;
    }
    else if(instruction == "mflo"){ //|| instruction == "mfhi"){
      //cout << "in mflo method" << endl;
      binaryLine.append("0000000000");
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      binaryLine.append("00000");
      if(instruction == "mflo"){
        registerBinary = mipsDictionary["0x12"];
        binaryLine.append(registerBinary);
      //add 0x12
      }
      else{
        registerBinary = mipsDictionary["0x10"];
        binaryLine.append(registerBinary);
        //add 0x10
      }
      binary.push_back(binaryLine);
    }
    else if(instruction == "div" || instruction == "mult"){
      cout << "mult" <<endl;
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      registers = asm_line.at(2);
      registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      binaryLine.append("00000000000");
      if(instruction == "div"){
        registerBinary = mipsDictionary["0x1a"];
        binaryLine.append(registerBinary);
      //add 0x1a
      }
      else{
        registerBinary = mipsDictionary["0x18"];
        binaryLine.append(registerBinary);
        //add 0x18
      }
    }
    else if(instruction == "sll"|| instruction == "srl"){
      //add rs??
      string registers = asm_line.at(2);
      string registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      registers = asm_line.at(1);
      registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      string number = asm_line.at(3);
      string binaryNum = intToBinary(number);
      binaryLine.append(binaryNum);
      //add shamt
      if (instruction == "sll"){
        binaryLine.append("000000");
      }
      else{
        binaryLine.append("000010");
      }
      binary.push_back(binaryLine);
    }
    else if (instruction == "jalr"){
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      binaryLine.append("00000");
      registers = asm_line.at(2);
      registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      binaryLine.append("00000");
      binaryLine.append("001001");
      binary.push_back(binaryLine);
    }
    else if(instruction == "jr"){
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers, mipsDictionary);
      binaryLine.append(registerBinary);
      binaryLine.append("000000000000000");
      binaryLine.append("001000");
      binary.push_back(binaryLine);
    }

    else if(instruction == "syscall"){
      binaryLine.append("00000000000000000000");
      string registerBinary = mipsDictionary["0x18"];
      binaryLine.append(registerBinary);
      //add 0x18
      binary.push_back(binaryLine);
    }

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
    //cout << "in addi" <<endl;
    string binaryLine = instructionBinary;
    //cout << "binaryLine: "<< binaryLine <<endl;

    string register1 = asm_line.at(2);
    string registerBinary = registerToBinary(register1, mipsDictionary);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(1);
    registerBinary = registerToBinary(register2, mipsDictionary);
    binaryLine.append(registerBinary);
    string number = asm_line.at(3);
    string binaryNum = intToBinary(number);
    binaryLine.append(binaryNum);
    //cout << "binaryLine: "<< binaryLine <<endl;
    binary.push_back(binaryLine);
  }
  else if (instructionBinary == "0x23" || instructionBinary == "0x2b") //lw and sw
  {
    string offset;
    string register1;
    string binaryLine = mipsDictionary[instructionBinary];
    string registers = asm_line.at(2);
    for(int i =0; i < registers.length(); i++){
      if(registers[i]=='('){
        offset = registers.substr(0, i); //number
        register1 = registers.substr(i+1, 3);
        i = registers.length();
      }
    }
    string registerBinary = registerToBinary(register1, mipsDictionary);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(1);
    registerBinary = registerToBinary(register2, mipsDictionary);
    binaryLine.append(registerBinary);
    binaryLine.append(intToBinary(offset));

  }
  else{//instructionBinary == "null"
    //pseudoInstructions(asm_line, binary, mipsDictionary);
  }

}
infile.close();
cout << binary.size() << endl;

//for(int x =0; x<binary.size(); x++){
  //cout << binary[x] << endl;
//}
return binary;
}


vector<string> Assembler::binaryToHex(vector<string> binary, vector<string> hex, map<string, string> mipsDictionary){
  string segment;
  string index;
  string hexNum;

    // loop for binary vector
  for(int k = 0; k < binary.size(); k++){
    index = binary.at(k);
    hexNum = "";

    // loop for each index
    for(int i = 0; i < index.size(); i+=4){
      segment = "";

        // loop for seperation by 4
      for(int j = 0; j < 4; j++){
        segment += index.at(i+j);
      }
      hexNum += mipsDictionary.at(segment);

    }
    hex.push_back(hexNum);     // add hex to vector
  }
  return hex;
}




int main(int argc, char* argv[]){
  vector<string> binary;
  vector<string> hex;
  Assembler asm_one(argv[1], binary, hex);
  vector<string> answer = asm_one.mipsToBinary();

//  answer = asm_one.binaryToHex(answer,hex, asm_one.mipsDictionary);
  for(int x =0; x<answer.size(); x++){
    cout << answer[x] << endl;
  }
}
