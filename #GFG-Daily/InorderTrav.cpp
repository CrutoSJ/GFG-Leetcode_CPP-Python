// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/inorder-traversal/1

// Date-> 07/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void solve(Node* node,vector<int> &res){
        if(!node)
        return;
        
        solve(node->left,res);
        res.push_back(node->data);
        solve(node->right,res);
    }
    vector<int> inOrder(Node* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }
};