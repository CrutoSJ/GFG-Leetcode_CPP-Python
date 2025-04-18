// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1

// Date-> 18/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node* children[26];
        bool flag; // end of word flag
    
        Node() {
            flag = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    class Trie {
    private:
        Node* root;
    
    public:
        Trie() {
            root = new Node();
        }
    
        void insert(string &word) {
            Node* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new Node();
                }
                node = node->children[index];
            }
            node->flag = true;
        }
    
        bool search(string &word) {
            Node* curr = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (curr->children[index] == nullptr) {
                    return false;
                }
                curr = curr->children[index];
            }
            return curr->flag;
        }
    
        bool isPrefix(string &word) {
            Node* curr = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (curr->children[index] == nullptr) {
                    return false;
                }
                curr = curr->children[index];
            }
            return true;
        }
    };