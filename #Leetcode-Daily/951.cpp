// #Question:-

// Link-> https://leetcode.com/problems/flip-equivalent-binary-trees/description/?envType=daily-question&envId=2024-10-24

// Date-> 24/10/24

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
    // Checks whether the given pair of nodes should be examined -
    // be pushed into the stack
    bool checkNodeValues(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 && node2 && node1->val == node2->val) return true;
        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Initialize stack to store pairs of nodes
        stack<pair<TreeNode*, TreeNode*>> nodePairStack;
        nodePairStack.push({root1, root2});

        // While the stack is not empty:
        while (!nodePairStack.empty()) {
            auto [node1, node2] = nodePairStack.top();
            nodePairStack.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;

            // Check both configurations: no swap and swap
            if (checkNodeValues(node1->left, node2->left) &&
                checkNodeValues(node1->right, node2->right)) {
                nodePairStack.push({node1->left, node2->left});
                nodePairStack.push({node1->right, node2->right});
            } else if (checkNodeValues(node1->left, node2->right) &&
                       checkNodeValues(node1->right, node2->left)) {
                nodePairStack.push({node1->left, node2->right});
                nodePairStack.push({node1->right, node2->left});
            } else {
                return false;
            }
        }
        return true;
    };
};