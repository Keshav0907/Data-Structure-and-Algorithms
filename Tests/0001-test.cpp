#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../0001-two-sum/0001-two-sum.cpp"

using namespace std;

TEST(test, test1)
{
    vector<int> nums = {2, 7, 11, 15};
    ASSERT_EQ(vector<int>({1, 0}), Solution().twoSum(nums, 9));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
