// #Question:-

// Link-> https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

// Date-> 25/06/24

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
    void Solve(TreeNode* root, int &sum){
        if (root==NULL) return;
        Solve(root->right, sum);
        sum += root->val;
        root->val = sum;
        Solve(root->left, sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        int sum=0;
        Solve(root, sum);
        return root;
    }
};