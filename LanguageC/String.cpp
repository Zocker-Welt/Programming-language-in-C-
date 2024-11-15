#include <string>
#include <map>

std::map<std::string, std::string> strings;

void setString(std::string name, std::string val) {
    strings[name] = val;
}

void setStringMain(std::string line) {
    /*
    Commands:
    
    string str << text
    Make and change string variables
    */
    std::string line2, line3;
    line2 = line.substr(7, line.size());
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
    setString(name, val);
}