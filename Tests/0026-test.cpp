#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../0026-remove-duplicates-from-sorted-array/0026-remove-duplicates-from-sorted-array.cpp"
using namespace std;

TEST(test, test1)
{
    vector<int> nums = {1, 1, 2};
    ASSERT_EQ(2, Solution().removeDuplicates(nums));
}
TEST(test, test2)
{
    vector<int> nums = {1, 1, 2, 2, 3};
    ASSERT_EQ(3, Solution().removeDuplicates(nums));
}

TEST(test, test3)
{
    vector<int> nums = {1, 1};
    ASSERT_EQ(1, Solution().removeDuplicates(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
