// #Question:-

// Link-> https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/?envType=daily-question&envId=2024-10-26

// Date-> 26/10/24

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
    int level[100001];
    int height[100001];
    int LmaxH[100001];
    int LSmaxH[100001];

    int findHeight(TreeNode* root, int l){
        if(!root){
            return 0;
        }

        level[root->val] = l;
        height[root->val] = max(findHeight(root->left, l+1), findHeight(root->right, l+1)) + 1;

        if(LmaxH[l] < height[root->val]){
            LSmaxH[l] = LmaxH[l];
            LmaxH[l] = height[root->val];
        } else if(LSmaxH[l] < height[root->val]){
            LSmaxH[l] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);

        vector<int> result;

        for(auto &node : queries){
            int L = level[node];

            int tempRes = L + (LmaxH[L] == height[node] ? LSmaxH[L] : LmaxH[L]) - 1;

            result.push_back(tempRes);
        }

        return result;
    }
};