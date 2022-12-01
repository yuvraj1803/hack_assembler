//
// Created by Yuvraj Sakshith on 25/11/22.
//

#include "Symbol_Table/symbol_table.h"


using namespace std;

symbol_table::symbol_table(){

    symbol_table::table["R0"]=0;
    symbol_table::table["R1"]=1;
    symbol_table::table["R2"]=2;
    symbol_table::table["R3"]=3;
    symbol_table::table["R4"]=4;
    symbol_table::table["R5"]=5;
    symbol_table::table["R6"]=6;
    symbol_table::table["R7"]=7;
    symbol_table::table["R8"]=8;
    symbol_table::table["R9"]=9;
    symbol_table::table["R10"]=10;
    symbol_table::table["R11"]=11;
    symbol_table::table["R12"]=12;
    symbol_table::table["R13"]=13;
    symbol_table::table["R14"]=14;
    symbol_table::table["R15"]=15;

    symbol_table::table["SCREEN"]=16384;
    symbol_table::table["KBD"]=24576;

    symbol_table::table["SP"]=0;
    symbol_table::table["LCL"]=1;
    symbol_table::table["ARG"]=2;
    symbol_table::table["THIS"]=3;
    symbol_table::table["THAT"]=4;

}

int symbol_table::lookup(string &field) {
        return symbol_table::table.find(field) != symbol_table::table.end();
}

void symbol_table::add(string &field, int address){
    if(symbol_table::table.find(field) == symbol_table::table.end()) symbol_table::table[field] = address;
}
int symbol_table::get(string &field){
    return symbol_table::table[field];
}