#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>


auto greet(std::string name) {
    std::ostringstream stream;
    stream << "Hello, " << name << "!" << std::endl;
    return stream.str();
}

int main(int argc, char** argv){
    auto greeting = greet("Felix");
    std::cout << greeting << std::endl;

    return EXIT_SUCCESS;
}