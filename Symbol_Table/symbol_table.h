//
// Created by Yuvraj Sakshith on 25/11/22.
//

#ifndef HACK_ASSEMBLER_SYMBOL_TABLE_H
#define HACK_ASSEMBLER_SYMBOL_TABLE_H

#include <map>
#include <string>
using namespace std;

class symbol_table {
private:
    map<string, int> table;
public:
    symbol_table();
    int lookup(string &field);
    void add(string &field, int address);
    int get(string &field);

};


#endif //HACK_ASSEMBLER_SYMBOL_TABLE_H
