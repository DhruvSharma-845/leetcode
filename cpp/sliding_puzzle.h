#include <vector>
#include <string>
#include <unordered_set>
#include <utility>
#include <queue>

class Solution {
private:
    auto stringifyBoard(const std::vector<std::vector<int>>& board) -> std::string {
        std::string s{""};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                s += std::to_string(board[i][j]);
            }
        }
        return s;
    }
public:
    int slidingPuzzle(std::vector<std::vector<int>>& board) {
        
        std::unordered_set<std::string> visited;
        std::string stringifiedBoard = stringifyBoard(board);

        std::queue<std::pair<std::string, int>> q;
        q.push(std::make_pair(stringifiedBoard, 0));
        visited.insert(stringifiedBoard);

        while(!q.empty()) {
            auto currentBoard = q.front();
            q.pop();

            if(currentBoard.first == "123450") {
                return currentBoard.second;
            }

            auto currentEmptyPos = currentBoard.first.find("0");

            std::vector<int> xDir{0, -1, 0, 1};
            std::vector<int> yDir{-1, 0, 1, 0};

            for(int turn = 0; turn < 4; turn++) {
                int nextX = (currentEmptyPos / 3) + xDir[turn];
                int nextY = (currentEmptyPos % 3) + yDir[turn];

                if(nextX >= 0 && nextY >= 0 && nextX < 2 && nextY < 3) {
                    int newEmptyPos = nextX * 3 + nextY;
                    std::string newBoard = currentBoard.first;
                    std::swap(newBoard[currentEmptyPos], newBoard[newEmptyPos]);
                    if(visited.find(newBoard) == visited.end()) {
                        visited.insert(newBoard);
                        q.push(std::make_pair(newBoard, currentBoard.second + 1));
                    }
                }
            }
        }
        return -1;
    }
};