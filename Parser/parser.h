//
// Created by Yuvraj Sakshith on 25/11/22.
//

#ifndef HACK_ASSEMBLER_PARSER_H
#define HACK_ASSEMBLER_PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include "Symbol_Table/symbol_table.h"
#include "Translator/translator.h"

using namespace std;

class parser {
private:
    vector<string> code;

    string file;
    string removeComments(string &line);
    string removeSpaces(string &line);
    string integerToBinaryString(int n);


    bool checkEmptyString(string &line);

public:
    vector<string> parse();
    explicit parser();
     bool fileError = false;
     vector<string> machineCode;
     vector<string> displayCode();
     void loadFile(string &assembly_file);


};


#endif //HACK_ASSEMBLER_PARSER_H
