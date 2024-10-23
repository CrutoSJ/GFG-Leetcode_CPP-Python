// #Question:-

// Link-> https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23

// Date-> 23/10/24

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);
        int levSum = root->val;

        while(!q.empty()){
            int n = q.size();
            int nxtLvlSum = 0;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                curr->val = levSum - curr->val;

                int sibSum = (curr->left != NULL ? curr->left->val : 0);
                sibSum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left){
                    nxtLvlSum += curr->left->val;
                    curr->left->val = sibSum;
                    q.push(curr->left);
                }

                if(curr->right){
                    nxtLvlSum += curr->right->val;
                    curr->right->val = sibSum;
                    q.push(curr->right);
                }
            }
            levSum = nxtLvlSum;
        }
        return root;
    }
};