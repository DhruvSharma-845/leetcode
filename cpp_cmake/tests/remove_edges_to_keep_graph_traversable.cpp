//
// Created by Dhruv Sharma on 10/07/25.
//

#include "remove_edges_to_keep_graph_traversable.h"

#include <gtest/gtest.h>

TEST(Remove_Edges_To_Keep_Graph_Traversable, BasicAssertions) {
    Solution s;
    std::vector<std::vector<int>> graph{{3, 1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    auto result = s.maxNumEdgesToRemove(4, graph);

    EXPECT_EQ(result, 2);
}
