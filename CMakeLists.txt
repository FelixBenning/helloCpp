cmake_minimum_required(VERSION 3.10)

# set project name
project(helloWorld VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add libraries
add_subdirectory(greeter)

# add executable
add_executable(helloWorld helloWorld.cpp)
# link libraries
target_link_libraries(helloWorld PRIVATE greeter)
