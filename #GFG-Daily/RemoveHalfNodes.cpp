// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/remove-half-nodes/1

// Date-> 20/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    Node *RemoveHalfNodes(Node *root) {
        if(root == NULL){
            return NULL;
        }
        
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        
        if(root->left != NULL && root->right == NULL){
            return root=root->left;
        }
        
        if(root->left == NULL && root->right != NULL){
            return root=root->right;
        }
        
        return root;
    }
};