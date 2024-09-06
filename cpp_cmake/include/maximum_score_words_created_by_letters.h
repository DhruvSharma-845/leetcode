#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    bool canWordBeCreated(const std::string& word, std::unordered_map<char, int> letterCount) {
        for(const char& c: word) {
            if(letterCount.find(c) != letterCount.end() && letterCount[c] > 0) {
                --letterCount[c];
            }
            else {
                return false;
            } 
        }
        return true;
    }

    int calculateScoreOfWord(const std::string& word, const std::vector<int>& score) {
        int wordScore = 0;
        for(const char& c: word) {
            wordScore += score[c - 'a'];
        }
        return wordScore;
    }

    void maxScoreWordsUtil(
        std::vector<std::string>& words, 
        std::unordered_map<char, int>& letterCount,
        std::vector<int>& score,
        int currentWordIndex,
        int currentScore,
        int& maxScore
    ) {
        if(currentWordIndex == words.size()) {
            if(currentScore > maxScore) {
                maxScore = currentScore;
            }
            return;
        }
        // without the current word
        this->maxScoreWordsUtil(words, letterCount, score, currentWordIndex + 1, currentScore, maxScore);

        // with current word
        // if the word can be created
        if(this->canWordBeCreated(words[currentWordIndex], letterCount)) {
            // deduct the letters
            for(const char& c: words[currentWordIndex]) {
                --letterCount[c];
            }
            auto newScore = calculateScoreOfWord(words[currentWordIndex], score) + currentScore;
            this->maxScoreWordsUtil(words, letterCount, score, currentWordIndex + 1, newScore, maxScore);
            // restore the letters
            for(const char& c: words[currentWordIndex]) {
                ++letterCount[c];
            }
        }
    }
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
        int maxScore = 0;
        std::unordered_map<char, int> letterCount;
        for(const char& c: letters) {
            letterCount[c]++;
        }
        this->maxScoreWordsUtil(words, letterCount, score, 0, 0, maxScore);
        return maxScore;
    }
};