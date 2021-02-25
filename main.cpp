#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "greet.h"


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