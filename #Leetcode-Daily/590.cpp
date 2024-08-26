// #Question:-

// Link-> https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26

// Date-> 26/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void solve(Node* root, vector<int> &result){
        if(root == NULL){
            return;
        }

        for(auto child : root->children ){
            solve(child, result);
        }

        result.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int>result;
        if(root == NULL){
            return result;
        }

        solve(root, result);
        return result;
    }
};