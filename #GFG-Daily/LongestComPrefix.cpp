// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

// Date -> 31/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCnt;
        bool isTerminal;
        
        TrieNode(char ch){
            this->data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            childCnt = 0;
            isTerminal = false;
        }
};

class Trie{
    TrieNode* root;
    
    public:
    
    Trie(char ch){
        root = new TrieNode(ch);
    }
    
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        
        int idx = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[idx] != NULL){
            child = root->children[idx];
        } else {
            child = new TrieNode(word[0]);
            root->childCnt++;
            root->children[idx] = child;
        }
        
        insertUtil(child, word.substr(1));
    }
    
    void insert(string word){
        insertUtil(root, word);
    }
    
    void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            
            if(root->childCnt == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            } else{
                break;
            }
            
            if(root->isTerminal){
                break;
            }
        }
    }
    
};

class Solution {
public:

    string longestCommonPrefix(vector<string> arr) {
        
        Trie* t = new Trie('\0');
        
        for(int i=0; i<arr.size(); i++){
            t->insert(arr[i]);
        }
        
        string first = arr[0];
        string ans = "";
        
        t->lcp(first, ans);
        if(ans.size() == 0){
            return "-1";
        }
        return ans;
        
    }
};