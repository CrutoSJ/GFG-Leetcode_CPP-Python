// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/check-for-bst/1

// Date-> 11/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
class Solution{
    private:
    bool solve(Node* root, int min, int max){
        if(root == NULL){
            return true;
        }
        
        if(root->data > min && root->data < max ){
            bool left = solve(root->left, min, root->data);
            bool right = solve(root->right, root->data, max);
            return left&&right;
        }
        
        return false;
    }
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        bool ans = solve(root, INT_MIN, INT_MAX);
        return ans;
    }
};