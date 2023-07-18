#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../0028-find-the-index-of-the-first-occurrence-in-a-string/0028-find-the-index-of-the-first-occurrence-in-a-string.cpp"

TEST(test, test1)
{
    ASSERT_EQ(0, Solution().strStr("a", ""));
}

TEST(test, test2)
{
    ASSERT_EQ(-1, Solution().strStr("mississippi", "a"));
}

TEST(test, test3)
{
    ASSERT_EQ(0, Solution().strStr("a", "a"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
