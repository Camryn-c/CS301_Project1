//Assembler Project1
//Camryn Carter and Jayana Turner
//Header file
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Assembler{
  private:
    map<string, string> dictionary;
    string filename;
    vector<string> binary;
    vector<string> hex;

  public:
    Assembler(string inputfile);
    ~Assembler();
    vector<string> Assembler::mipsToBinary(vector<string> binary, map<string, string> dictionary);
    void Assembler::binaryToHex(vector<string> binary, vector<string> hex);
    void Assembler::pseudoInstructions(string mips, vector<string> binary);

    string Assembler::instructionsToBinary(string instruction);
    string Assembler::registerToBinary(string registers); 
    string Assembler::intToBinary(string number);


};
