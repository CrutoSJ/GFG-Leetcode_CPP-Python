// #Question:-

// Given the root of a binary search tree and a number n, find the greatest number in the binary search tree that is less than or equal to n.

// Link-> https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

class Solution {
  public:
    void findFromBST(int &ans, Node* root, int &n){
        if(root==NULL) return;
        if(root->key==n){
            ans = n;
            return;
        }
        if(root->key<n){
            ans = root->key;
            findFromBST(ans, root->right, n);
        }
        else{
            findFromBST(ans, root->left, n);
        }
        return;
    }
    
    int findMaxForN(Node* root, int n) {
        int ans = -1;
        findFromBST(ans, root, n);
        if(ans==-1) return -1;
        return ans;
    }
};