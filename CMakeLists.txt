cmake_minimum_required(VERSION 3.10)

# set project name
project(helloWorld VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# include test module (must be in top level file!)
include(CTest)

# compiler options
message(STATUS "Updating Compiler Options")
if(CMAKE_BUILD_TYPE MATCHES Debug)
	message(STATUS "adding Debug compiler options")
	add_compile_options("-Wall" "-Wextra" "-Werror" "-pedantic")
	add_compile_options("-O0")
endif()
if(CMAKE_BUILD_TYPE MATCHES Release)
	message(STATUS "adding Release compiler options")
	add_compile_options("-O3")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
	message(STATUS "adding MSVC compiler options")
	add_compile_options("/permissive-") # standards conformance
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add libraries
add_subdirectory(greeter)
# libraries for tests
add_subdirectory(googletest)
add_subdirectory(tests)

# add executable
add_executable(helloWorld helloWorld.cpp)
# link libraries
target_link_libraries(helloWorld PRIVATE greeter)
