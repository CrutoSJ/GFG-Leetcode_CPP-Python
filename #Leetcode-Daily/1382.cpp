// #Question:-

// Link-> https://leetcode.com/problems/balance-a-binary-search-tree/

// Date-> 26/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void inOrder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    TreeNode* solve(vector<int>arr, int s, int e){
        if(s>e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = solve(arr, s, mid-1);
        root->right = solve(arr, mid+1, e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;
        vector<int>arr;
        inOrder(root,arr);
        return solve(arr,0,arr.size()-1);
    }
};