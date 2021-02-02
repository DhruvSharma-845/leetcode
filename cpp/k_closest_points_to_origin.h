#include <vector>
#include <queue>
#include <utility>
#include <cmath>

class Solution {
    template<class T>
    using Queue_Element = std::pair<T, std::vector<int>>;
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int K) {
        auto comparator = [](const Queue_Element<int>& a, const Queue_Element<int>& b) {
            return a.first < b.first;
        };
        std::priority_queue<Queue_Element<int>, std::vector<Queue_Element<int>>, decltype(comparator)> que(comparator);
        int i = 0;
        for(; i < K; ++i) {
            int dist = std::pow(points[i][0], 2) + std::pow(points[i][1], 2);
            que.push(std::make_pair(dist, points[i]));
        }
        for(; i < points.size(); ++i) {
            int dist = std::pow(points[i][0], 2) + std::pow(points[i][1], 2);
            if(que.top().first > dist) {
                que.pop();
                que.push(std::make_pair(dist, points[i]));
            }
        }
        std::vector<std::vector<int>> res;
        for(i = 0; i < K; ++i) {
            res.push_back(que.top().second);
            que.pop();
        }
        return res;
    }
};