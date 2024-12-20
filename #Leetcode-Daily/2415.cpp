// #Question:-

// Link-> https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2024-12-20

// Date-> 20/12/24

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
    void solveDFS(TreeNode* leftC, TreeNode* rightC, int lvl){
        if(leftC == NULL || rightC == NULL){
            return;
        }

        if(lvl % 2 == 0){
            int tmp = leftC->val;
            leftC->val  = rightC->val;
            rightC->val = tmp;
        }

        solveDFS(leftC->left, rightC->right, lvl+1);
        solveDFS(leftC->right, rightC->left, lvl+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        solveDFS(root->left, root->right, 0);
        return root;
    }
};