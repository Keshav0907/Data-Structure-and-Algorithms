#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../0015-3sum/0015-3sum.cpp"

TEST(test, test1)
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    ASSERT_EQ(expected, Solution().threeSum(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
