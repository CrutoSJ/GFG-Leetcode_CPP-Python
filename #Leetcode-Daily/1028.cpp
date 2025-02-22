// #Question:-

// Link-> https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/?envType=daily-question&envId=2025-02-22

// Date-> 22/02/25

// #Solution:-

#include <bits/stdc++.h>
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
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> stack;
            int index = 0;
    
            while (index < traversal.size()) {
                int depth = 0;
                while (index < traversal.size() && traversal[index] == '-') {
                    depth++;
                    index++;
                }
    
                int value = 0;
                while (index < traversal.size() && isdigit(traversal[index])) {
                    value = value * 10 + (traversal[index] - '0');
                    index++;
                }
    
                TreeNode* node = new TreeNode(value);
    
                while (stack.size() > depth) {
                    stack.pop();
                }
    
                if (!stack.empty()) {
                    if (stack.top()->left == nullptr) {
                        stack.top()->left = node;
                    } else {
                        stack.top()->right = node;
                    }
                }
    
                stack.push(node);
            }
    
            while (stack.size() > 1) {
                stack.pop();
            }
    
            return stack.top();
        }
    };