#include <vector>
#include <iostream>


class Solution {
private:
    auto hasConflictingQueenInColumn(const std::vector<std::vector<bool>>& board, int row, int column) -> bool {
        for(int i = 0; i < board.size(); ++i) {
            if(board[i][column] == true) {
                return true;
            }
        }
        return false;
    }
    auto hasConflictingQueenInRow(const std::vector<std::vector<bool>>& board, int row, int column) -> bool {
        for(int i = 0; i < board.size(); ++i) {
            if(board[row][i] == true) {
                return true;
            }
        }
        return false;
    }
    auto hasConflictingQueenInDiagonals(const std::vector<std::vector<bool>>& board, int row, int column) -> bool {
        // Bottom to Top Diagonal
        for(int currentRow = 0; currentRow < board.size(); ++currentRow) {
            int currentColumn = row + column - currentRow;
            if(currentColumn >= 0 && currentColumn < board[0].size() && board[currentRow][currentColumn] == true) {
                return true;
            }
        }

        // Top to bottom Diagonal
        for(int currentRow = 0; currentRow < board.size(); ++currentRow) {
            int currentColumn = currentRow - (row - column);
            if(currentColumn >= 0 && currentColumn < board[0].size() && board[currentRow][currentColumn] == true) {
                return true;
            }
        }

        return false;
    }
    auto totalQueensUtil(int n, int currentRow, std::vector<std::vector<bool>>& board) -> int {
        if(currentRow == n) {
            return 1;
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(this->hasConflictingQueenInColumn(board, currentRow, i) == false 
                && this->hasConflictingQueenInRow(board, currentRow, i) == false
                && this->hasConflictingQueenInDiagonals(board, currentRow, i) == false) {
                    board[currentRow][i] = true;
                    count += this->totalQueensUtil(n, currentRow + 1, board);
                    board[currentRow][i] = false;
                }
        }
        return count;
    }
public:
    int totalNQueens(int n) {
        std::vector<std::vector<bool>> board(n, std::vector<bool>(n, false));
        return this->totalQueensUtil(n, 0, board);
    }
};