// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

// Date-> 12/07/24

// #Solution:

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    bool solve(Node* root, int target, int s){
        //base case:-
        if(root == NULL){
            return false;
        }
        //recursive case:-
        s=s+root->data;
        if(root->left == NULL && root->right==NULL){
            return s==target;
        }
        return solve(root->left, target, s) || solve(root->right, target, s);
        
    }
    bool hasPathSum(Node *root, int target) {
        int s=0;
        return solve(root, target, s);
    }
};