// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

// Date-> 12/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    private:
    void solve(Node* root, int &k, int &ans){
        if(root ==NULL)return;
        solve(root->left, k, ans);
        k--;
        if(k==0){
            ans=root->data;
            return ;
        }
        solve(root->right, k, ans);
    }
    public:
      // Return the Kth smallest element in the given BST
      int kthSmallest(Node *root, int k) {
        int ans=-1;
        solve(root, k, ans);
        return ans;
    }
};