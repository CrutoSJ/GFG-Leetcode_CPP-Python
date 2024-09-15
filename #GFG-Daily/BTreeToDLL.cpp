// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

// Date-> 15/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* head = NULL, *prvs = NULL; 
    void solve(Node* root){
        if(root==NULL){
            return ;
        }
        solve(root->left);
        if(head==NULL){
            head=root;
        }
        if(prvs!=NULL){
            prvs->right = root;
        }
        root->left = prvs;
        prvs = root;
        solve(root->right);
    }
    Node* bToDLL(Node* root) {
        solve(root);
        return head;
    }
};

