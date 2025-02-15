// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

// Date-> 15/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root==NULL){
            return root;
        }
        if(root->data < n1->data && root->data < n2->data){
            return LCA(root->right, n1, n2);
        } else if(root->data > n1->data && root->data > n2->data){
            return LCA(root->left, n1, n2);
        } else{
            return root;
        }
    }
};