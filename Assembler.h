//Assembler Project1
//Camryn Carter and Jayana Turner
//Header file
#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Assembler{
  private:
    string filename;
    vector<string> binary;
    vector<string> hex;


  public:
    map<string, string> mipsDictionary;

    Assembler(string inputfile);
    ~Assembler();

    vector<string> mipsToBinary(vector<string> binary, map<string, string> mipsDictionary);
    void binaryToHex(vector<string> binary, vector<string> hex, map<string, string> mipsDictionary);
    void pseudoInstructions(vector<string> mips, vector<string> binary, map<string, string> mipsDictionary);

    vector<string> split(string line, char delim);
    string instructionsToBinary(string instruction, map<string, string> mipsDictionary);
    string registerToBinary(string registers, map<string, string> mipsDictionary);
    string intToBinary(string number);


};
#endif
