// #Question:-

// Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution {
public:
void solve(Node* root, int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans = min(ans, root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    int minValue(Node* root) {
        // Code here
        int ans = INT_MAX;
        solve(root, ans);
        return ans;
    }
};