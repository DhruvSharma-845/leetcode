//
// Created by Dhruv Sharma on 10/07/25.
//

#ifndef REMOVE_EDGES_TO_KEEP_GRAPH_TRAVERSABLE_H
#define REMOVE_EDGES_TO_KEEP_GRAPH_TRAVERSABLE_H

#include <vector>

class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
public:
    explicit UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        int root = parent[i];

        if (parent[root] != root) {
            return parent[i] = find(root);
        }

        return root;
    }
    void unite(int i, int j) {
        int xRoot = find(i);
        int yRoot = find(j);
        if (xRoot == yRoot) {
            return;
        }
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    bool isFullyConnected() {
        int rootCount = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) {
                ++rootCount;
                if (rootCount == 2) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
        UnionFind ufAlice(n);
        UnionFind ufBob(n);

        int finalCount = 0;
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (ufAlice.find(edge[1] - 1) != ufAlice.find(edge[2] - 1)) {
                    ufAlice.unite(edge[1] - 1, edge[2] - 1);
                    ufBob.unite(edge[1] - 1, edge[2] - 1);
                }
                else {
                    ++finalCount;
                }
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                // Alice
                if (ufAlice.find(edge[1] - 1) != ufAlice.find(edge[2] - 1)) {
                    ufAlice.unite(edge[1] - 1, edge[2] - 1);
                }
                else {
                    ++finalCount;
                }
            }
            else if (edge[0] == 2) {
                // Bob
                if (ufBob.find(edge[1] - 1) != ufBob.find(edge[2] - 1)) {
                    ufBob.unite(edge[1] - 1, edge[2] - 1);
                }
                else {
                    ++finalCount;
                }
            }
        }
        return (ufAlice.isFullyConnected() && ufBob.isFullyConnected()) ? finalCount : -1;
    }
};

#endif //REMOVE_EDGES_TO_KEEP_GRAPH_TRAVERSABLE_H
