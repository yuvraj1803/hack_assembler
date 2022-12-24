//
// Created by Yuvraj Sakshith on 27/11/22.
//

#include "Assembler/Assembler.h"


Assembler::Assembler(std::string &assembly_file) { // passing the assembly file that needs to be processed

    HACK_PARSER.loadFile(assembly_file); // loading the file into the parser.
    
    if(HACK_PARSER.fileError){ // if there is an error opening the file.
        cout << "error loading the file. check the existance and file-permissions of the file" << '\n';
        return;
    }

    machine_code = HACK_PARSER.parse();   // contains the machine code
    clean_code = HACK_PARSER.displayCode();  // contains the code with comments, white-spaces, and table removed.

}
