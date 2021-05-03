#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    int calculateFrequencyOfSmallest(std::string& str) {
        std::sort(str.begin(), str.end());
        return std::count(str.begin(), str.end(), str[0]);
    }
public:
    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words) {
        std::vector<int> wordsFrequency(words.size(), 0);
        auto i = 0;
        for(auto& word: words) {
            wordsFrequency[i++] = calculateFrequencyOfSmallest(word);
        }
        std::sort(wordsFrequency.begin(), wordsFrequency.end());

        std::vector<int> queriesResult(queries.size(), 0);
        i = 0;
        for(auto& query: queries) {
            int queryFrequency = calculateFrequencyOfSmallest(query);
            auto pos = std::lower_bound(wordsFrequency.begin(), wordsFrequency.end(), queryFrequency);
            if(pos == wordsFrequency.end()) {
                queriesResult[i++] = 0;
            }
            else if((*pos) > queryFrequency) {
                queriesResult[i++] = wordsFrequency.size() - (pos - wordsFrequency.begin());
            }
            else if((*pos) == queryFrequency) {
                while(pos != wordsFrequency.end() && (*pos) == queryFrequency) {
                    ++pos;
                }
                if(pos == wordsFrequency.end()) {
                    queriesResult[i++] = 0;
                }
                else {
                    queriesResult[i++] = wordsFrequency.size() - (pos - wordsFrequency.begin());
                }
            }
        }
        return queriesResult;
    }
};