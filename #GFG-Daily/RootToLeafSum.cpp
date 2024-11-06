// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

// Date-> 06/11/24

// #SOlution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};

class Solution {
  public:
    int solve(Node* root, int num){
        if(!root){
            return 0;
        }
        num = 10 * num + root->data;
        if(!root->left && !root->right){
            return num;
        }
        return solve(root->left, num) + solve(root->right, num);
    }
    int treePathsSum(Node *root) {
        return solve(root,0);
    }
};