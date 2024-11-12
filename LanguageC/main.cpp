#include <iostream>
#include <string>
#include <vector>

// Libs
#include "String.cpp"
#include "Console.cpp"

int main() {
    std::vector<std::string> code = {
        "string str << This is a string variable", // str << String
        "out << s&str",
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
            std::string line2;
            line2 = line.substr(7, line.size());
            std::string spacer1;
            spacer1 = line2.substr(3, line2.size());
            if (spacer1[0] == ' ') {
                while (spacer1[0] == ' ') {
                    spacer1 = spacer1.substr(1, spacer1.size());
                }
            }
            line2 = line2.substr(0, 3) + spacer1;
            spacer1 = line2.substr(5, line2.size());
            if (spacer1[0] == ' ') {
                while (spacer1[0] == ' ') {
                    spacer1 = spacer1.substr(1, spacer1.size());
                }
            }
            line2 = line2.substr(0, 5) + spacer1;
            //std::cout << "\n" << line2;
            std::string name = line2.substr(0, line2.find("<"));
            std::string val = line2.substr(line2.find("<") + 2, size(line2));
            setString(name, val);
        }
        else if (line.substr(0, 3) == "out") {

            /*
            Commands

            out << t&text
            Output plain text

            out << s&str
            Output string variable
            */
            std::string line2;
            line2 = line.substr(line.find('<') + 2, line.size());
            if (line2[0] == ' ') {
                while (line2[0] == ' ') {
                    line2 = line2.substr(1, line2.size());
                }
            }
            if (line2.substr(0, 2) == "t&") {
                // Text output
                line2 = line2.substr(2, line2.size());
                stringOut(line2);
            }
            else if (line2.substr(0, 2) == "s&") {
                // String output
                line2 = line2.substr(2, line2.size());
                stringOut(strings[line2]);
            }
        }
    }

    return 0;
}