#include <greet.h>
#include <iostream>
#include <sstream>

std::string greet(std::string name) {
    std::ostringstream stream;
    stream << "Hello, " << name << "!" << std::endl;
    return stream.str();
}