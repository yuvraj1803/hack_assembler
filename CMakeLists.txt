cmake_minimum_required(VERSION 3.23)
project(hack_assembler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hack_assembler
        main.cpp
        Parser/parser.cpp
        Parser/parser.h
        Symbol_Table/symbol_table.cpp
        Symbol_Table/symbol_table.h
        Assembler/Assembler.cpp
        Assembler/Assembler.h
        Translator/translator.cpp
        Translator/translator.h)
