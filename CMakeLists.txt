cmake_minimum_required(VERSION 3.10)

# set project name
project(helloWorld VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include test module (must be in top level file!)
include(CTest)

# add libraries
add_subdirectory(greeter)
# libraries for tests
add_subdirectory(googletest)
add_subdirectory(tests)

# add executable
add_executable(helloWorld helloWorld.cpp)
# link libraries
target_link_libraries(helloWorld PRIVATE greeter)
