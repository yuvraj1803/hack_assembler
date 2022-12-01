//
// Created by Yuvraj Sakshith on 27/11/22.
//

#ifndef HACK_ASSEMBLER_ASSEMBLER_H
#define HACK_ASSEMBLER_ASSEMBLER_H

#include "Parser/parser.h"
#include <string>

class Assembler {
private:
    parser HACK_PARSER = *new parser();
public:

    Assembler(string &assembly_file);
    vector<string> machine_code;
    vector<string> clean_code;
};


#endif //HACK_ASSEMBLER_ASSEMBLER_H
