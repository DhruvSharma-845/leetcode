#include <vector>
#include <string>
#include <cmath>
#include <iostream>

class Solution {
private:
    bool canPlaceQueen(int row, int col, std::vector<std::string>& currentBoard) {
        // column check
        for(auto i = 0; i < currentBoard.size(); ++i) {
            if(currentBoard[i][col] == 'Q') {
                return false;
            }
        }

        // row check
        for(auto j = 0; j < currentBoard.size(); ++j) {
            if(currentBoard[row][j] == 'Q') {
                return false;
            }
        }

        // diagonals check
        // Left to right diagonal
        for(auto k = 0; k < currentBoard.size(); ++k) {
            int m = k - (row - col);
            if(m >= 0 && m < currentBoard.size() && currentBoard[k][m] == 'Q') {
                return false;
            }
        }
        // Right to left diagonal
        for(auto k = 0; k < currentBoard.size(); ++k) {
            int m = (row + col) - k;
            if(m >= 0 && m < currentBoard.size() && currentBoard[k][m] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solveNQueensUtil(int n, std::vector<std::vector<std::string>>& res, int currentRow, std::vector<std::string>& currentBoard) {
        if(currentRow >= n) {
            res.push_back(currentBoard);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(canPlaceQueen(currentRow, i, currentBoard)) {
                currentBoard[currentRow][i] = 'Q';
                solveNQueensUtil(n, res, currentRow + 1, currentBoard);
                currentBoard[currentRow][i] = '.';
            }
        }
    }
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> currentBoard(n, std::string(n, '.'));
        solveNQueensUtil(n, res, 0, currentBoard);
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cout << res[i][j] << std::endl;
            }
            std::cout << std::endl;
        }
        
        return res;
    }
};