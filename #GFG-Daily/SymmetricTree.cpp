// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/symmetric-tree/1

// Date-> 14/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  private:
    bool solve(Node* left, Node* right){
        if(left == NULL && right == NULL) return true;
        if((left == NULL && right != NULL) || (left != NULL && right == NULL)) return false;
        if(left->data != right->data) return false;
        
        return (solve(left->left, right->right) && solve(left->right, right->left));
    }
  public:
    bool isSymmetric(Node* root) {
        return solve(root->left, root->right);
    }
};
