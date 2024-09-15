#include <vector>

class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        std::vector<std::vector<int>> cumulativeSum(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                cumulativeSum[i][j] = matrix[i-1][j-1] + cumulativeSum[i-1][j] + cumulativeSum[i][j-1] - cumulativeSum[i-1][j-1];
            }
        }
        
        int numOfSubmatrices = 0;

        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                for(int m = i; m >= 1; --m) {
                    for(int n = j; n>= 1; --n) {
                        int currentSum = cumulativeSum[i][j] - 
                                        (m-1 < 0 ? 0 : cumulativeSum[m - 1][j]) - 
                                        (n-1 < 0 ? 0 : cumulativeSum[i][n-1]) + 
                                        (m-1 < 0 || n-1 < 0 ? 0 : cumulativeSum[m-1][n-1]);
                        if(currentSum == target) {
                            ++numOfSubmatrices;
                        }
                    }
                }
            }
        }
        return numOfSubmatrices;
    }
};