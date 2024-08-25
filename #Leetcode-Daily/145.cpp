// #Question:-

// Link-> https://leetcode.com/problems/binary-tree-postorder-traversal/description/

// Date-> 25/08/24

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
public:
    void getPostOrd(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        getPostOrd(root->left, ans);
        getPostOrd(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        getPostOrd(root, ans);
        return ans;
    }
};