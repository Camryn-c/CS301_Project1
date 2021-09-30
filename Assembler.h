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

  public:
    int lineCounter;
    string filename;
    string outfile;
    vector<string> binary;
    vector<string> hex;
    map<string, string> mipsDictionary;

    Assembler(string inputfile, string outputfile);
    ~Assembler();

    map<string, int> findLabels();
    vector<string> mipsToBinary();
    vector<string> binaryToHex();
    void pseudoInstructions();

    vector<string> split(string line);
    string instructionsToBinary(string instruction);
    string registerToBinary(string registers);
    string intToBinary(string number);


};
#endif
