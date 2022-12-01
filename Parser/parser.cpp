//
// Created by Yuvraj Sakshith on 25/11/22.
//

#include "Parser/parser.h"

void parser::loadFile(string &assembly_file){
    this->file = assembly_file;
    ifstream fileStream(assembly_file);
    if(!fileStream.is_open()) fileError = true;
    fileStream.close();
}

parser::parser() {

}

bool parser::checkEmptyString(std::string &line) {

    string temp;
    for(auto i: line){
        if(i == ' ') continue;
        temp += i;
    }
    return temp.empty();
}

string parser::removeSpaces(std::string &line) {
    string spacesRemoved;
    for(auto i:line){
        if(i == ' ') continue;
        spacesRemoved += i;
    }

    return spacesRemoved;
}

string parser::removeComments(std::string &line) {
    string commentsRemoved;
    for(auto i:line){
        if(i == '/') break;
        commentsRemoved += i;
    }

    return commentsRemoved;
}

string parser::integerToBinaryString(int n){
    string bin = "000000000000000";
    for(int i=0;i<15;i++){
        if(n & (1 << i)){
            bin[14-i] = '1';
        }
    }
    return bin;
}

vector<string> parser::displayCode() {
    return code;
}

vector<string> parser::parse() {

    ifstream fileStream(file);
    string line;
    while(getline(fileStream, line)){
        if(line.empty() || line[0] == '\r') continue;
        line = removeSpaces(line);
        line = removeComments(line);
        if(checkEmptyString(line)) continue;
        if(line.back() == '\r') line.pop_back(); // removing the '\r' from the end of the string
        code.push_back(line);
    }
    fileStream.close();

    vector<string> binCode;
    symbol_table ST = *new symbol_table();

    int currentAvailableAddress = 16;
    int lineNumber = 0;

    // First pass to add all the labels into the symbol-table
    vector<string> noLabelCode;
    for(auto line: code){
        if(line[0] == '('){
            string label = line.substr(1,line.size() - 2);
            ST.add(label,lineNumber);
        }else{
            if(line.empty()) continue;
            noLabelCode.push_back(line);
            lineNumber++;
        }
    }
    code = noLabelCode;

    lineNumber = 0;

    // Second pass

    for(auto line: code){
        if(line[0] == '@'){ // A type instruction
            string name = line.substr(1,line.size()-1);
            int isNum = 1;
            for(auto c : name){
                isNum &= isdigit(c);
            }
            if(isNum) {
                string binAddress = integerToBinaryString(stoi(name));
                binAddress.insert(0,"0");
                binCode.push_back(binAddress);
                continue;
            }
            if(ST.lookup(name)){
                int address = ST.get(name);
                string binAddress = integerToBinaryString(address);
                binAddress.insert(0,"0");
                binCode.push_back(binAddress);
            }else {
                ST.add(name, currentAvailableAddress);
                string binAddress = integerToBinaryString(currentAvailableAddress);
                binAddress.insert(0,"0");
                binCode.push_back(binAddress);
                currentAvailableAddress++;
            }
        }else{
            // C type instruction
            string dst,cmp,jmp; // for the dest, comp and jump parts respectively
            string curr;
            bool eq = false, semi_colon = false;

            for(auto c : line){
                if(c == '='){
                    dst = curr;
                    eq = true;
                    curr = "";
                }else if(c == ';'){
                    cmp = curr;
                    curr = "";
                    semi_colon = true;
                }else{
                    curr += c;
                }

                if(!curr.empty()){
                    if(semi_colon){
                        jmp = curr;
                    }else{
                        cmp = curr;
                    }
                }

            }

            string instruction;
            translator Translator = *new translator();
            instruction += Translator.comp(cmp, lineNumber);
            instruction += Translator.dest(dst, lineNumber);
            instruction += Translator.jump(jmp, lineNumber);

            instruction.insert(0,"111");
            binCode.push_back(instruction);
        }


        lineNumber++;
    }

    return binCode;

}