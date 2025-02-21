// #Question:-

// Link-> https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/?envType=daily-question&envId=2025-02-21

// Date-> 21/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class FindElements
{
public:
    FindElements(TreeNode *root) { dfs(root, 0); }

    bool find(int target) { return seen.count(target) > 0; }

private:
    unordered_set<int> seen;

    void dfs(TreeNode *currentNode, int currentValue)
    {
        if (!currentNode)
            return;
        seen.insert(currentValue);
        dfs(currentNode->left, currentValue * 2 + 1);
        dfs(currentNode->right, currentValue * 2 + 2);
    }
};