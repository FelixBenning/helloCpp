add_library(greeter STATIC greet.cpp)

# PUBLIC include makes header file available to targets linking to the greeter
# library (i.e. 'target_link_libraries(my_target [PUBLIC/PRIVATE] greeter)')
target_include_directories(greeter PUBLIC include)

# PRIVATE would make the directory only available to the target (i.e. greeter)
# itself