#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../0011-container-with-most-water/0011-container-with-most-water.cpp"

TEST(test, test1)
{
  std::vector<int> height = {1, 1};
  int expected = 1;
  ASSERT_EQ(expected, Solution().maxArea(height));
}

GTEST_API_ int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
