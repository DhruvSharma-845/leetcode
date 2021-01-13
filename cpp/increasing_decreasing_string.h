#include <string>
#include <vector>
class Solution {
public:
    std::string sortString(std::string s) {
        std::vector<int> counts(26, 0);
        
        for(char ch: s) {
            counts[static_cast<int>(ch) - 97]++;
        }

        int index = 0;
        while(true) {
            bool empty = true;
            for(int i = 0; i < 26; ++i) {
                if(counts[i] > 0) {
                    s[index++] = static_cast<char>(i) + 97;
                    --counts[i];
                    empty = false;
                }
            }
            if(empty == true) {
                break;
            }
            for(int i = 25; i >= 0; --i) {
                if(counts[i] > 0) {
                    s[index++] = static_cast<char>(i) + 97;
                    --counts[i];
                    empty = false;
                }
            }
            if(empty == true) {
                break;
            }
        }
        return s;
    }
};