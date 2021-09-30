//Assembler Project1
//Camryn Carter and Jayana Turner
//Assembler c++ file

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include "Assembler.h"

using namespace std;


//constructor
//parameters: a string of the input file used to read the asm file and the name
//of the output file
//This method assigns the input file name to the variable filename, assigns
//default variables to the vectors, and creates a Dictionary
Assembler::Assembler(string inputfile, string outputfile){
  this->lineCounter = 0;
  this->filename = inputfile;
  this->binary = binary;
  this->hex = hex;
  this->outfile = outputfile;

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
}

//destructor
//clears the values in the vector binary and the vector hex
Assembler::~Assembler(){
  binary.clear();
  hex.clear();
}


//Finds the labels within the asm file and the next instruction line number
//returns a map that contains the label and the next instruction's line numbers
map<string, int> Assembler::findLabels(){
  map<string, int> labelDictionary;
  int counter = 0;
  //opens the file and reads it line by line
  ifstream infile(filename);
  string line;
  int lineLen =0;
  string newLine;
  while (getline(infile, line)){
    lineLen = line.length();
    //want to find the label based on : and also making sure that : isnt found in a comment
    //then adds it to the dictionary
    if(line.find(':') != -1 && line.find('#') == -1){
      for(int x =0; x<lineLen-1; x++){
        if(line[x]!=':' && line[x] != ' '){
          newLine +=line[x];
        }
      }
      labelDictionary.insert({newLine, counter});
      newLine ="";
    }
    else{
    counter++;
    }
  }
  //returns the dictionary
  return labelDictionary;
}

//Instructions to Binary method
//convert asm instructions to its binary representation
//parameters is the string asm instruction and the dictionary that holds the binary
//representations of the instructions
//if it in the dictionary it returns the binary representation if it isnt it returns null
string Assembler::instructionsToBinary(string instruction){
  if (mipsDictionary.count(instruction) > 0){
    string binary = mipsDictionary.at(instruction);
    return binary;
  }
  else{
    return "null";
  }
}

//coverts the asm register to its binary representation
//parameters is a string asm register and the dictionary that holds the binary
//representations of the instructions
//returns a string of the binary number
string Assembler::registerToBinary(string registers){
  string binary = mipsDictionary[registers];
  return binary;
}

//converts the number to its binary representation
//parameters is a string of the number
string Assembler::intToBinary(string immediate){
  //converts the number into a int
  vector<char> binaryNum;
  int num = stoi(immediate);
  int og_num = num;
  string numbers;

  //makes the number positive
  if (num < 0){
    num = num * -1;
  }

  //creates a vector of the binary number
  while (num > 0){
    if (num%2 == 1){
      binaryNum.push_back('1');
      num = num - 1;
      num = num/2;
    }
    else{
      binaryNum.push_back('0');
      num = num/2;
    }
  }

  //puts the binary number in the correct order and makes sure that it is 16 bits
  for (int j = binaryNum.size(); j<16; j++){
    numbers += "0";
  }
  int binaryLen = binaryNum.size();
  for(int i=1; i<=binaryLen; i++){
    numbers += binaryNum.at((binaryNum.size())-i);
  }

  //if the number was negative it does twos complement to get the negative binary
  //representation of the int
  if (og_num < 0){
    vector<char> negativeNum;
    string inverse = "";
    string one = "0000000000000001";
    int numLen = numbers.length();
    //first create the inverse
    for(int x=0; x<numLen ; x++){
        if (numbers.substr(x,1) == "0"){
          inverse += "1";
        }
        else{
          inverse += "0";
        }
    }
    char carry ='0';
    //adding one to the inverse
    for(int y=one.length()-1; y>=0; y--){
      if(inverse.substr(y,1)=="0" && one.substr(y,1)=="0" && carry == '0'){
        negativeNum.push_back('0');
      }
      else if(inverse.substr(y,1)=="0" && one.substr(y,1)=="0" && carry == '1'){
        negativeNum.push_back('1');
        carry = '0';
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
    int negativeLen = negativeNum.size();
    for(int i=1; i<=negativeLen; i++){
      numbers += negativeNum.at((negativeNum.size())-i);
    }
    return numbers;
  }
  else{
    return numbers;
  }
}

//splits a string based on spaces and also ignores commas
//parameters string
//returns a vector containing the seperated string
vector<string> Assembler::split(string line){

  char delim = ' ';
  vector<string> words;
  size_t pos = 0;
  string lineCopy;
  // removes commas from the line
  //and if there is a comment at the end it reomves the space
  int i = 0;
  int lineLen = line.length();
  while(line[i] == ' '){
    i++;
  }
  while(i < lineLen){
    if(line[i] != ','){
      if(line[i] == ' ' && i != lineLen-1){
        if(line[i+1] == '#'){
          i++;
        }
        else{
          lineCopy += line[i];
          i++;
        }
      }
      else{
        lineCopy += line[i];
        i++;
      }
    }
    else{
      i++;
    }
  }

// seperates the line by whitespace and puts it into a vector
 pos = lineCopy.find(delim);
  while(pos != -1){
    words.push_back(lineCopy.substr(0,pos));
    lineCopy.erase(0, pos + 1);
    pos = lineCopy.find(delim);
  }
  words.push_back(lineCopy.substr(0,pos));

  int vectorLen =  words.size();
  string newString;
  //removes the comments and comm from the last instruction/register within the line
  for (int x =0; x< vectorLen; x++){
    string temp = words.at(x);
    int stringLen = temp.length();
    for (int y = 0; y < stringLen; y++){
      if(temp[y]=='#'){
        for(int i =0; i<y; i++){
          newString += temp[i];
        }
        int loopLen = vectorLen-x;
        for(int a =0; a<loopLen; a++){
          words.pop_back();
        }
        words.push_back(newString);
        //onnce it has found the comments and deleted them exit the for loop
        y = stringLen;
        x = vectorLen;
      }
    }
  }
  return words;
}

//will handle the pseudo Instructions
void Assembler::pseudoInstructions(){

}

//Reads through the file line by line and makes each line a string
//using the other ...toBinary methods it converts each line of the file into binar
//returns a vector of strings that holds the binary of the instructions
vector<string> Assembler::mipsToBinary(){
//opens and reads the file line by line
  map<string, int> labelDictionary = findLabels();
  ifstream infile(filename);
  string line;
 while (getline(infile, line)){
  vector<string> asm_line;
  //splits the line
  asm_line = split(line);
  string instruction = asm_line.at(0);

  //continues the conversion to binary based on the first instruction
  string instructionBinary = instructionsToBinary(instruction);
  if (instructionBinary == "000000"){
    string binaryLine = instructionBinary;
    //handles add, sub, and slt instructions
    if (instruction == "add" || instruction == "sub" || instruction == "slt"){
      string registers = asm_line.at(2);
      string registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      registers = asm_line.at(3);
      registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      registers = asm_line.at(1);
      registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      binaryLine.append("00000");
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
      }
      //adds the line to a vector that holds all the binary lines
      binary.push_back(binaryLine);
    }
    else if(instruction == "mflo"|| instruction == "mfhi"){
      //handles mflo and mfhi instructions
      binaryLine.append("0000000000");
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      binaryLine.append("00000");
      if(instruction == "mflo"){
        registerBinary = mipsDictionary["0x12"];
        binaryLine.append(registerBinary);
      }
      else{
        registerBinary = mipsDictionary["0x10"];
        binaryLine.append(registerBinary);
      }
      //adds the line to a vector that holds all the binary lines
      binary.push_back(binaryLine);
    }
    else if(instruction == "div" || instruction == "mult"){
      //handles div and mult instructions
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      registers = asm_line.at(2);
      registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      binaryLine.append("0000000000");
      if(instruction == "div"){
        registerBinary = mipsDictionary["0x1a"];
        binaryLine.append(registerBinary);
      }
      else{
        registerBinary = mipsDictionary["0x18"];
        binaryLine.append(registerBinary);
      }
      //adds the line to a vector that holds all the binary lines
      binary.push_back(binaryLine);
    }
    else if(instruction == "sll"|| instruction == "srl"){
      //handles sll and srl instructions
      binaryLine.append("00000");
      string registers = asm_line.at(2);
      string registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      registers = asm_line.at(1);
      registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      string number = asm_line.at(3);
      string binaryNum = intToBinary(number);
      binaryLine.append(binaryNum.substr(binaryNum.length()-5));
      if (instruction == "sll"){
        binaryLine.append("000000");
      }
      else{
        binaryLine.append("000010");
      }

      //adds the line to a vector that holds all the binary lines
      binary.push_back(binaryLine);
    }
    //handles jalr instruction
    else if (instruction == "jalr"){
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      binaryLine.append("00000");
      registers = asm_line.at(2);
      registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      binaryLine.append("00000");
      binaryLine.append("001001");
      binary.push_back(binaryLine);
    }
    //handles jr instruction
    else if(instruction == "jr"){
      string registers = asm_line.at(1);
      string registerBinary = registerToBinary(registers);
      binaryLine.append(registerBinary);
      binaryLine.append("000000000000000");
      binaryLine.append("001000");

      //adds the line to a vector that holds all the binary lines
      binary.push_back(binaryLine);
    }
    //handles syscall instruction
    else if(instruction == "syscall"){
      binaryLine.append("00000000000000000000");
      string registerBinary = mipsDictionary["0x18"];
      binaryLine.append(registerBinary);

      //adds the line to a vector that holds all the binary lines
      binary.push_back(binaryLine);
    }
  } //if it equals 000000 (add, sub, sll, srl, mult, div, jr, jal r, mflo, mfhi, syscall)

  //handles bne instruction
  else if (instructionBinary == "000101")
  {
    string binaryLine = instructionBinary;
    string registers = asm_line.at(1);
    string registerBinary = registerToBinary(registers);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(2);
    registerBinary = registerToBinary(register2);
    binaryLine.append(registerBinary);

    //finds the offset
    string label = asm_line.at(3);
    int instructionNum = labelDictionary.at(label);
    string newNum = to_string(instructionNum-(lineCounter+1));
    string binaryNum = intToBinary(newNum);
    binaryLine.append(binaryNum);

    //adds the line to a vector that holds all the binary lines
    binary.push_back(binaryLine);
  }
  //handles beq instruction
  else if (instructionBinary == "000100")
  { //we can concatenate strings or have a vector of vectors
    string binaryLine = instructionBinary;
    string registers = asm_line.at(1);
    string registerBinary = registerToBinary(registers);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(2);
    registerBinary = registerToBinary(register2);
    binaryLine.append(registerBinary);

    //find the offset
    string label = asm_line.at(3);
    int instructionNum = labelDictionary.at(label);
    string newNum = to_string(instructionNum-(lineCounter+1));
    string binaryNum = intToBinary(newNum);
    binaryLine.append(binaryNum);

    //adds the line to a vector that holds all the binary lines
    binary.push_back(binaryLine);
  }

  //handles j instruction
  else if (instructionBinary == "000010")
  {
    string binaryLine = instructionBinary;
    string label = asm_line.at(1);
    string instructionNum = to_string(labelDictionary.at(label));
    string zero = "0000000000";
    string binaryNum = intToBinary(instructionNum);
    string newBinaryNum = zero;
    newBinaryNum += binaryNum;
    binaryLine.append(newBinaryNum);

    //adds the line to a vector that holds all the binary lines
    binary.push_back(binaryLine);
  }

  //handles jal instruction
  else if (instructionBinary == "000011")
  {
    string binaryLine = instructionBinary;
    string label = asm_line.at(1);
    string instructionNum = to_string(labelDictionary.at(label));
    string zero = "0000000000";
    string binaryNum = intToBinary(instructionNum);
    string newBinaryNum = zero;
    newBinaryNum += binaryNum;
    binaryLine.append(newBinaryNum);

    //adds the line to a vector that holds all the binary lines
    binary.push_back(binaryLine);
  }

  //handles addi instruction
  else if (instructionBinary == "001000")
  {
    string binaryLine = instructionBinary;
    string register1 = asm_line.at(2);
    string registerBinary = registerToBinary(register1);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(1);
    registerBinary = registerToBinary(register2);
    binaryLine.append(registerBinary);
    string number = asm_line.at(3);
    string binaryNum = intToBinary(number);
    binaryLine.append(binaryNum);

    //adds the line to a vector that holds all the binary lines
    binary.push_back(binaryLine);
  }

  //handles lw and sw instructions
  else if (instructionBinary == "0x23" || instructionBinary == "0x2b") //lw and sw
  {
    string offset;
    string register1;
    string binaryLine = mipsDictionary[instructionBinary];
    string registers = asm_line.at(2);
    int registerLen = registers.length();
    //finds the register and offset and ignores the ()
    for(int i =0; i <registerLen; i++){
      if(registers[i]=='('){
        offset = registers.substr(0, i);
        register1 = registers.substr(i+1, 3);
        i = registers.length();
      }
    }
    string registerBinary = registerToBinary(register1);
    binaryLine.append(registerBinary);
    string register2 = asm_line.at(1);
    registerBinary = registerToBinary(register2);
    binaryLine.append(registerBinary);
    binaryLine.append(intToBinary(offset));

    //adds the line to a vector that holds all the binary lines
    binary.push_back(binaryLine);
  }
  else{
    //it is a label and is not added to the file
    //in the future can handle psedoInstructions
  }
  lineCounter++;
}

//after reading the file close the file
infile.close();
//return the vector with binary instructions
return binary;
}

//converts binary into hex
//parameters: the binary vector that holds the lines of binary, hex vector that will hold the
//instructions in hex, the dictionary
//returns a vector that contains the hex instructions and outputs a file
vector<string> Assembler::binaryToHex(){
  string segment;
  string index;
  string hexNum;
  ofstream file;

  //opens output file
  file.open(outfile);
  file << "v3.0 hex words plain" << endl;

    // loop for binary vector
  int binarySize = binary.size();
  int indexSize;
  for(int k = 0; k < binarySize; k++){
    index = binary.at(k);
    hexNum = "";
    indexSize = index.size();
    // loop for each index
    for(int i = 0; i < indexSize; i+=4){
      segment = "";

        // loop for seperation by 4
      for(int j = 0; j < 4; j++){
        segment += index.at(i+j);
      }
      hexNum += mipsDictionary.at(segment);

    }
    hex.push_back(hexNum);     // add hex to vector
    file << hexNum << endl;
  }

  file.close();
  return hex;
}

//main
//parameters input file name and out put file name
//an output file should be generated contianing the hex representations of the mips instruction
int main(int argc, char* argv[]){
  Assembler asm_one(argv[1], argv[2]);
  vector<string> answer = asm_one.mipsToBinary();
}
//end file
