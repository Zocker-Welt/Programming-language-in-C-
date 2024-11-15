#include <iostream>
#include <string>
#include <map>

void outMain(std::string line) {
    /*
    Command
    out << t&text
    Output plain tex
    out << s&str
    Output string variable
    out
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
        std::cout << line2;
    }
    else if (line2.substr(0, 2) == "s&") {
        // String output
        line2 = line2.substr(2, line2.size());
        std::cout << strings[line2];
    }
    else if (line2.substr(0, 2) == "i&") {
        // Int output
        line2 = line2.substr(2, line2.size());
        std::cout << ints[line2];
    }

}