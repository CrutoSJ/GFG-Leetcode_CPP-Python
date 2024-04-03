// #Question:-

// Link->  https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

//Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

};

class Solution {
    public:
    void fun(Node* root, int &ans, int &prev) {
        if(root==NULL) return;
        fun(root->left, ans, prev);
        if(prev!=-1) ans=min(ans,abs(root->data - prev));
        prev=root->data;
        fun(root->right, ans, prev);
    }
    
    int absolute_diff(Node *root) {
        int ans=INT_MAX, prev=-1;
        fun(root,ans,prev);
        return ans;
    }
};