// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

// Date-> 09/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    bool checkDead(Node* root, int mini, int maxi){
        if(root == NULL){
            return false;
        }
        
        if(root->left == NULL && root->right == NULL){
            if(root->data - mini == 1 && maxi - root->data == 1){
                return true;
            } else{
                return false;
            }
        }
        
        return checkDead(root->left, mini, root->data) || checkDead(root->right, root->data, maxi);
    }
  public:
    bool isDeadEnd(Node *root) {
        return checkDead(root, 0, INT_MAX);
    }
};