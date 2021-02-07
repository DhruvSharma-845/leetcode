#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string arrangeWords(std::string text) {
        std::vector<std::string> tokens;
        std::istringstream tokenStream(text);
        std::string token;
        while(std::getline(tokenStream, token, ' ')) {
            tokens.push_back(token);
        }

        std::stable_sort(tokens.begin(), tokens.end(), [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        });

        std::string resStr;
        for(int i = 0; i < tokens.size(); ++i) {
            if(i == 0) {
                tokens[i][0] = toupper(tokens[i][0]);
            }
            else if(isupper(tokens[i][0])) {
                tokens[i][0] = tolower(tokens[i][0]);
            }
            resStr += (tokens[i] + " ");
        } 
        return (resStr.size() > 0 ? resStr.substr(0, resStr.size() - 1) : resStr);       
    }
};