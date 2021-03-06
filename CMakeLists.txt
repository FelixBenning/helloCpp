cmake_minimum_required(VERSION 3.10)

# set project name
project(helloWorld VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include test module (must be in top level file!)
include(CTest)

### compiler options
if(MSVC) # is MS visual studio compiler
	message(STATUS "Updating MSVC Compiler Options")
	add_compile_options(/permissive- /MT) # standards conformance, static version of runtime lib
	add_compile_options("$<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:/W4;/WX>")
	add_compile_options("$<$<CONFIG:Debug>:/Od>") # disable optimization
	add_compile_options("$<$<OR:$<CONFIG:Release>,$<CONFIG:RelWithDebInfo>>:/02>") # fast
	add_compile_options("$<$<CONFIG:MinSizeRel>:/O1>") # small
else() # GNU or Clang
	message(STATUS "Updating Compiler Options")
	add_compile_options( # debug information
		"$<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:-Wall;-Wextra;-Werror;-pedantic>"
	)
	add_compile_options("$<$<CONFIG:Debug>:-O0>") # disable optimization
	add_compile_options("$<$<OR:$<CONFIG:Release>,$<CONFIG:RelWithDebInfo>>:-O3>") # fast
	add_compile_options("$<$<CONFIG:MinSizeRel>:-Os>") # small
endif()

# generate `compile_commands.json` listing all the compile commands
# useful for debugging and used by clangd (language server) to provide C++ IDE features
# important as `target_include_directories` is translated to `-I` options
# which provide information on where to find header files
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
