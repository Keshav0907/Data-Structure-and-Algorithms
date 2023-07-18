#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;

#include "../0034-find-first-and-last-position-of-element-in-sorted-array/0034-find-first-and-last-position-of-element-in-sorted-array.cpp"


TEST(test, test1)
{
    vector<int> nums = {1, 2, 3};
    ASSERT_EQ(vector<int>({1, 1}), Solution().searchRange(nums, 2));
}

TEST(test, test2)
{
    vector<int> nums = {};
    ASSERT_EQ(vector<int>({-1, -1}), Solution().searchRange(nums, 0));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
