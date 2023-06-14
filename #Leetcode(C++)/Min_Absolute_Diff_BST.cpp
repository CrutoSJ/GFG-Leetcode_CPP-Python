// Question:-

// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

// Solution:-

class Solution {
    int minDiff=INT_MAX;
    TreeNode* prevNode;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prevNode){
            minDiff=min(minDiff,root->val - prevNode->val);
        }
        prevNode=root;
        inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};