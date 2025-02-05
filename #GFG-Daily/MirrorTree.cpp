// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/mirror-tree/1

// Date-> 13/09/24 && 05/02/25

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
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL){
            return ;
        }
        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
    }
};