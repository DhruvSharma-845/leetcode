//
// Created by Dhruv Sharma on 11/05/25.
//

#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

struct TrieNode {
    std::vector<TrieNode*> children;

    bool isLeaf = false;

    TrieNode(): children(26, nullptr) {}
};

void insertTrieUtil(TrieNode* node, const std::string& str, int index) {
    if (index == str.size()) {
        node->isLeaf = true;
        return;
    }
    char currentChar = str[index];
    int childIndex = currentChar - 'a';
    if (node-> children[childIndex] == nullptr) {
        node->children[childIndex] = new TrieNode();
    }
    insertTrieUtil(node->children[childIndex], str, index + 1);
}

void insertTrie(TrieNode* node, const std::string& str) {
    insertTrieUtil(node, str, 0);
}

TrieNode* searchTrieUtil(TrieNode* node, const std::string& str, int index) {
    if (index == str.size()) {
        return node;
    }
    int childIndex = str[index] - 'a';
    if (node->children[childIndex] != nullptr) {
        return searchTrieUtil(node->children[childIndex], str, index + 1);
    }
    return nullptr;
}

TrieNode* searchTrie(TrieNode* node, const std::string& str) {
    return searchTrieUtil(node, str, 0);
}





#endif //TRIE_H
