#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>


auto greet(std::string name) {
    std::ostringstream stream;
    stream << "Hello, " << name << "!" << std::endl;
    return stream.str();
}

int main(int argc, char* argv[]){
    std::string greeting;
    if (argc > 1) {
        std::string name = argv[1];
        greeting = greet(name);
    } else {
        greeting = "Hello World!";
    }
    
    std::cout << greeting << std::endl;

    return EXIT_SUCCESS;
}