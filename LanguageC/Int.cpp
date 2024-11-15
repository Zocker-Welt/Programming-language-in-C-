#include <string>
#include <map>
#include <iostream>

std::map<std::string, int> ints;

void setInt(std::string name, int val) {
    ints[name] = val;
}

void setIntMain(std::string line) {
    /*
    Commands:

    int integer << 456
    Make and change int variables
    */
    std::string line2, line3;
    line2 = line.substr(4, line.size());
    std::string spacer1;
    
    spacer1 = line2.substr(3, line2.size());
    for (int i = 0; i < line2.size(); i++) {
        if (i > line2.find('<') + 2){
            line3 += line2[i];
        }
        else if (line2[i] != ' ') {
            line3 += line2[i];
        }
    }
    std::string name, val;
    name = line3.substr(0, line3.find('<'));
    val = line3.substr(line3.find('<') + 2, line3.size());
    setInt(name, std::stoi(val));
}