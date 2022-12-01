//
// Created by Yuvraj Sakshith on 25/11/22.
//

#ifndef HACK_ASSEMBLER_TRANSLATOR_H
#define HACK_ASSEMBLER_TRANSLATOR_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

class translator {

private:
    map<string,string> compT,destT,jumpT; // T stands for table

public:

    translator();

    string comp(string &field, int line);
    string dest(string &field, int line);
    string jump(string &field, int line);

};


#endif //HACK_ASSEMBLER_TRANSLATOR_H
