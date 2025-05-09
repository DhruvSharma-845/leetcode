#include <grid_can_be_cut_into_sections.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(GridCanBeCutIntoSections, BasicAssertions1) {
    Solution s;

    std::vector<std::vector<int>> rectangle{
        {1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}
    };
    EXPECT_EQ(s.checkValidCuts(5, rectangle), true);

    std::vector<std::vector<int>> rectangle2{
        {0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}
    };
    EXPECT_EQ(s.checkValidCuts(4, rectangle2), true);

    std::vector<std::vector<int>> rectangle3{
        {0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}
    };
    EXPECT_EQ(s.checkValidCuts(4, rectangle3), false);

    
}