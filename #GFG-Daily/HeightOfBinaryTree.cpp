// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

// Date-> 03/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to find the height of a binary tree.
    int getHeight(Node* node){
        if(node == NULL){
            return 0;
        }
        
        int left =getHeight(node->left);
        int right=getHeight(node->right);
        
        int res = max(left, right)+1;
        return res;
    }
    int height(Node* node) {
        int ans = getHeight(node);
        return ans-1;
    }
};