// #Question:-

// Link-> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23

// Date-> 23/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder,
                                   vector<int> &postorder)
    {
        int numOfNodes = preorder.size();
        return constructTree(0, numOfNodes - 1, 0, preorder, postorder);
    }

private:
    TreeNode *constructTree(int preStart, int preEnd, int postStart,
                            vector<int> &preorder, vector<int> &postorder)
    {
        if (preStart > preEnd)
            return NULL;

        if (preStart == preEnd)
        {
            return new TreeNode(preorder[preStart]);
        }

        int leftRoot = preorder[preStart + 1];

        int numOfNodesInLeft = 1;
        while (postorder[postStart + numOfNodesInLeft - 1] != leftRoot)
        {
            numOfNodesInLeft++;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);

        root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                   postStart, preorder, postorder);

        root->right =
            constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                          postStart + numOfNodesInLeft, preorder, postorder);

        return root;
    }
};