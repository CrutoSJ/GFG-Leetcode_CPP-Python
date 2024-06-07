// #Question:-

// Link-> https://leetcode.com/problems/replace-words/?envType=daily-question&envId=2024-06-07

//Date -> 07/06/2024

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word = "";
    };
    
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;
    }
    
    string replace(const string& word, TrieNode* root) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                break;
            }
            node = node->children[c];
            if (!node->word.empty()) {
                return node->word;
            }
        }
        return word;
    }
    
    string replaceWords(vector<string>& dict, string sen) {
        TrieNode* root = new TrieNode();
        for (const string& word : dict) {
            insert(root, word);
        }
        
        stringstream ss(sen);
        string token, result;
        bool first = true;
        
        while (ss >> token) {
            if (!first) {
                result += " ";
            } else {
                first = false;
            }
            result += replace(token, root);
        }
        
        return result;
    }
};
