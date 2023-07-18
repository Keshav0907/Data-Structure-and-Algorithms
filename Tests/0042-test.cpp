#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;

#include "../0042-trapping-rain-water/0042-trapping-rain-water.cpp"


TEST(test, test1)
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    ASSERT_EQ(6, Solution().trap(height));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
