//
// Created by Dhruv Sharma on 15/06/25.
//

#include "maximum_target_nodes_II.h"
#include "utils.h"

#include <gtest/gtest.h>

TEST(Maximum_Target_Nodes_II, BasicAssertions) {
    Solution s;
    graph_edges edges1{{0,1},{0,2},{2,3},{2,4}};
    graph_edges edges2{{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    std::vector<int> res = s.maxTargetNodes(edges1, edges2);
    std::vector<int> expected{8,7,7,8,8};
    compareVectors(res, expected);
}
