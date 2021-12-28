#include <vector>
#include <string>

class Solution {
private:
    bool doDFS(int rows, int cols, const std::vector<std::vector<char>>& board, const std::string& word, int row, int col) {
        int wordLength = word.length();
        // Left to right
        if(col == 0 || board[row][col-1] == '#') {
            if(col + wordLength <= cols) {
                bool notPossible = false;
                for(int i = 0; i < wordLength; i++) {
                    if(board[row][i + col] != ' ' && board[row][i + col] != word[i]) {
                        notPossible = true;
                        break;
                    }
                }
                if(notPossible == false && ((col + wordLength) == cols || board[row][col + wordLength] == '#')) {
                    return true;
                }
            }
        }

        // Right to Left
        if(col == cols - 1 || board[row][col+1] == '#') {
            if(col - wordLength >= -1) {
                bool notPossible = false;
                for(int i = 0; i < wordLength; i++) {
                    if(board[row][col - i] != ' ' && board[row][col - i] != word[i]) {
                        notPossible = true;
                        break;
                    }
                }
                if(notPossible == false && ((col - wordLength) == -1 || board[row][col - wordLength] == '#')) {
                    return true;
                }
            }
        }

        // Top to Down
        if(row == 0 || board[row-1][col] == '#') {
            if(row + wordLength <= rows) {
                bool notPossible = false;
                for(int i = 0; i < wordLength; i++) {
                    if(board[row + i][col] != ' ' && board[row + i][col] != word[i]) {
                        notPossible = true;
                        break;
                    }
                }
                if(notPossible == false && ((row + wordLength) == rows || board[row + wordLength][col] == '#')) {
                    return true;
                }
            }
        }

        // Down to Top
        if(row == rows - 1 || board[row+1][col] == '#') {
            if(row - wordLength >= -1) {
                bool notPossible = false;
                for(int i = 0; i < wordLength; i++) {
                    if(board[row - i][col] != ' ' && board[row - i][col] != word[i]) {
                        notPossible = true;
                        break;
                    }
                }
                if(notPossible == false && ((row - wordLength) == -1 || board[row - wordLength][col] == '#')) {
                    return true;
                }
            }
        }


        return false;
    }
public:
    bool placeWordInCrossword(std::vector<std::vector<char>>& board, std::string word) {
        auto rows = static_cast<int>(board.size());
        auto cols = static_cast<int>(board[0].size());
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; ++j) {
                if(board[i][j] == ' ' || board[i][j] == word[0]) {
                    if(doDFS(rows, cols, board, word, i, j) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};