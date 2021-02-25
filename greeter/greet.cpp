
#include <iostream>
#include <sstream>

auto greet(std::string name) {
    std::ostringstream stream;
    stream << "Hello, " << name << "!" << std::endl;
    return stream.str();
}