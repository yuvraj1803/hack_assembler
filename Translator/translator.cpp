//
// Created by Yuvraj Sakshith on 25/11/22.
//

#include "Translator/translator.h"

translator::translator() {
    translator::destT[""] = "000";
    translator::destT["M"] = "001";
    translator::destT["D"] = "010";
    translator::destT["MD"] = "011";
    translator::destT["A"] = "100";
    translator::destT["AM"] = "101";
    translator::destT["AD"] = "110";
    translator::destT["AMD"] = "111";

    translator::compT["0"] = "0101010";
    translator::compT["1"] = "0111111";
    translator::compT["-1"] = "0111010";
    translator::compT["D"] = "0001100";
    translator::compT["A"] = "0110000";
    translator::compT["!D"] = "0001101";
    translator::compT["!A"] = "0110001";
    translator::compT["-D"] = "0001111";
    translator::compT["-A"] = "0110011";
    translator::compT["D+1"] = "0011111";
    translator::compT["A+1"] = "0110111";
    translator::compT["D-1"] = "0001110";
    translator::compT["A-1"] = "0110010";
    translator::compT["D+A"] = "0000010";
    translator::compT["D-A"] = "0010011";
    translator::compT["A-D"] = "0000111";
    translator::compT["D&A"] = "0000000";
    translator::compT["D|A"] = "0010101";
    translator::compT["M"] = "1110000";
    translator::compT["!M"] = "1110001";
    translator::compT["-M"] = "1110011";
    translator::compT["M+1"] = "1110111";
    translator::compT["M-1"] = "1110010";
    translator::compT["D+M"] = "1000010";
    translator::compT["D-M"] = "1010011";
    translator::compT["M-D"] = "1000111";
    translator::compT["D&M"] = "1000000";
    translator::compT["D|M"] = "1010101";

    translator::jumpT[""] = "000";
    translator::jumpT["JGT"] = "001";
    translator::jumpT["JEQ"] = "010";
    translator::jumpT["JGE"] = "011";
    translator::jumpT["JLT"] = "100";
    translator::jumpT["JNE"] = "101";
    translator::jumpT["JLE"] = "110";
    translator::jumpT["JMP"] = "111";
}

string translator::comp(string &field, int line) {
    if(translator::compT.find(field)!=translator::compT.end()) return translator::compT[field];
    cout << "error: check line " << line << '\n';
    exit(1);
}

string translator::dest(string &field, int line) {
    if(field.empty()) return "000";
    if(translator::destT.find(field)!=translator::destT.end()) return translator::destT[field];
    cout << "error: check line " << line << '\n';
    exit(1);}

string translator::jump(string &field, int line) {
    if(field.empty()) return "000";
    if(translator::jumpT.find(field)!=translator::jumpT.end()) return translator::jumpT[field];
    cout << "error: check line " << line << '\n';
    exit(1);
}