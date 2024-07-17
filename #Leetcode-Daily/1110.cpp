// #Question:-

// Link-> https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17

// Date-> 17/07/24

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
    TreeNode* deleteHelper(TreeNode* root, vector<TreeNode*> &ans, unordered_set<int> &dltNodes){
        if(root == NULL){
            return NULL;
        }

        root->left = deleteHelper(root->left, ans, dltNodes);
        root->right = deleteHelper(root->right, ans, dltNodes);

        if(dltNodes.find(root->val) != dltNodes.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        } else{
            return root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>dltNodes;

        for(auto &i: to_delete){
            dltNodes.insert(i);
        }

        deleteHelper(root, ans,dltNodes);

        if(dltNodes.find(root->val) == dltNodes.end()){
            ans.push_back(root);
        }

        return ans;
    }
};