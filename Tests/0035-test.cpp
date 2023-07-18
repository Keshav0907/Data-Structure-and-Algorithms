#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;

#include "../0035-search-insert-position/0035-search-insert-position.cpp"

TEST(test, test1)
{
    vector<int> nums = {1, 3, 5, 6};
    ASSERT_EQ(2, Solution().searchInsert(nums, 5));
}

TEST(test, test2)
{
    vector<int> nums = {1};
    ASSERT_EQ(0, Solution().searchInsert(nums, 1));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
