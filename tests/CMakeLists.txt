
add_executable(test_greeter test_greeter.cpp)

target_link_libraries(test_greeter PRIVATE greeter gtest gtest_main)

add_test(
	NAME greeter 
	COMMAND test_greeter
)