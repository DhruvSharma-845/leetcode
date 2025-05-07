#include <filling_bookcase_shelves.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(FillingBookcaseShelves, BasicAssertions1) {
    Solution s;

    std::vector<std::vector<int>> books{
        {1,1},
        {2,3},{2,3},
        {1,1},{1,1},
        {1,1},{1,2}
    };
    EXPECT_EQ(s.minHeightShelves(books, 4), 6);
}