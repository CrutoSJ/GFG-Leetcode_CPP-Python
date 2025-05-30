// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

// Date-> 30/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    void solve(Node* root, int k, int &num){
        if(root == NULL){
            return ;
        }
        
        if(root->data <= k){
            num = max(num, root->data);
        }
        
        if(root->data > k){
            solve(root->left, k, num);
        }
        
        if(root->data < k){
            solve(root->right, k, num);
        }
        
        return ;
    }
  public:
    int findMaxFork(Node* root, int k) {
        int num = -1;
        solve(root, k, num);
        return num;
    }
};