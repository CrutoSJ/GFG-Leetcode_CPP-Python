// #Question:-

// Link->  https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

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