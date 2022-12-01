//
// Created by Yuvraj Sakshith on 27/11/22.
//

#include "Assembler/Assembler.h"


Assembler::Assembler(std::string &assembly_file) {

    HACK_PARSER.loadFile(assembly_file);
    if(HACK_PARSER.fileError){
        cout << "error loading the file. check the existance and file-permissions of the file" << '\n';
        return;
    }

    machine_code = HACK_PARSER.parse();
    clean_code = HACK_PARSER.displayCode();

}