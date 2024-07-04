// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/duplicate-subtrees/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
private:
    string solve(Node* root, unordered_map<string, int> &map, vector<Node*> &ans){
        if(root == NULL){
            return "N";
        }
        
        string s = to_string(root->data) + "," + solve(root->left, map, ans) + "," + solve(root->right, map, ans);
        map[s]++;
        if(map[s]==2){
            ans.push_back(root);
        }
        return s;
    }
public:
    vector<Node*> printAllDups(Node* root) {
        unordered_map<string,int>map;
        vector<Node*>ans;
        solve(root, map, ans);
        return ans;
    }
};