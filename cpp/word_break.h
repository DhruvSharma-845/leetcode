#include <iostream>
#include <vector>
#include <string>

struct TrieNode {
    bool isWord;
    std::vector<TrieNode*> children;
};

class Trie {
private:
    int alphabet;
    TrieNode* root;
public:
    Trie(int capacity): alphabet(capacity), root(new TrieNode()) {
        root->isWord = false;
        root->children.resize(alphabet);
    }
    void insert(std::string& str);
    bool search(std::string& str, int start, int end);
};

void Trie::insert(std::string& str) {
    TrieNode* r{root};
    int currentPos = 0;
    while(currentPos < str.length()) {
        int index = static_cast<int>(str[currentPos]) - 97;
        
        if(r->children[index] == nullptr) {
            TrieNode* t = new TrieNode();
            t->isWord = false;
            t->children.resize(alphabet);
            r->children[index] = t;
        }
        r = r->children[index];
        currentPos++;
    }
    if(r != nullptr) {
        r->isWord = true;
    }
}

bool Trie::search(std::string& str, int start, int end) {
    TrieNode* r{root};
    while(r != nullptr && start <= end) {
        int index = static_cast<int>(str[start]) - 97;
        r = r->children.at(index);
        start++;
    }
    if(r != nullptr) {
        return r->isWord;
    }
    return false;
}

class Solution {
public:
    bool wordBreak(std::string& s, std::vector<std::string>& wordDict) {
        Trie t{26};
        for(auto& word: wordDict) {
            t.insert(word);
        }

        std::vector<bool> table(s.length(), false);
        for (size_t i = 0; i < s.length(); i++) {
            for (int j = i; j >= 0; j--) {
                auto prevRes = bool{false};
                if(j == 0) {
                    prevRes = true;
                }
                else {
                    prevRes = table[j-1];
                }
                if(prevRes && t.search(s, j, i)) {
                    table[i] = true;
                }
            }
        }
        return table[s.length() - 1];
    }
};