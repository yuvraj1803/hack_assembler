//
// Created by Yuvraj Sakshith on 25/11/22.
//

#include <iostream>
#include <fstream>

#include "Assembler/Assembler.h"

using namespace std;

int main(int argc, char * argv[]){

    if(argc == 3){
        if(strcmp(argv[1],"-c") != 0){
            cout << "incorrect flags passed." << '\n';
            exit(1);
        }

    }
    if(argc < 2){
        cout << "input format: hack-assembler <flags> <file-name>" << '\n';
        exit(1);
    }



    string file = argv[argc-1];

    Assembler hack_assembler = *new Assembler(file);

    string outfile = file.substr(0,file.size()-4);
    outfile += ".hack";
    vector<string> mc = hack_assembler.machine_code;
    ofstream of(outfile);
    for(const auto& i:mc) of << i << '\n';
    of.close();

    if(argc == 3 and !strcmp(argv[1],"-c")){
        int lineNr = 0;
        for(auto i: hack_assembler.clean_code){
            cout << lineNr << ':' << i << '\n';
            lineNr++;
        }
    }

    exit(0);
}