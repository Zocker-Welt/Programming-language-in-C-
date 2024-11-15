#include <iostream>
#include <string>
#include <vector>

// Libs
#include "String.cpp"
#include "Int.cpp"
#include "Console.cpp"

int main() {
    std::vector<std::string> code = {
        "string string << This is a string variable\n",
        "int integer << 456",
        "",
        "out << s&string",
        "out << i&integer",
        "out << t&\nThis is plain text"
        };
    for (int l = 0; l < size(code); l++) {
        std::string line = code[l];
        if (line.substr(0, 6) == "string") {
            /*
            Commands:
            
            string str << text
            Make and change string variables
            */
           setStringMain(line);
        }
        else if (line.substr(0, 3) == "int") {
            /*
            Commands:

            int integer << 456
            Make and change int variables
            */
            setIntMain(line);
        }
        else if (line.substr(0, 3) == "out") {
            /*
            Commands

            out << t&text
            Output plain text

            out << s&str
            Output string variable
            */
            //outMain(line, strings, ints);
            outMain(line);
        }
    }

    return 0;
}