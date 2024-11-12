#include <string>
#include <map>

std::map<std::string, std::string> strings;

void setString(std::string name, std::string val) {
    strings[name] = val;
}