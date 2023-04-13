#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;

#include "../0050-powx-n/0050-powx-n.cpp"

TEST(test, test1)
{
    ASSERT_EQ(1024.00000, Solution().myPow(2.00000, 10));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
