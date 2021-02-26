#include <gtest/gtest.h>
#include <greet.h>

TEST(greeter, greet){
	ASSERT_EQ("Hello, world!\n", greet("world"));	
}

// linking gtest_main proivides such a main function already
/*
int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/
