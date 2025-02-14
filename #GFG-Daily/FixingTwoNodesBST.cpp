// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

// Date-> 14/02/25

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
      Node *prev, *temp, *first ,*second;
      void inorder(Node* root){
          if(root==NULL){
              return;
          }
          inorder(root->left);
          if(prev && root->data < prev->data){
              if(first==NULL){
                  first=prev;
                  temp=root;
              } else{
                  second=root;
              }
          }
          prev=root;
          inorder(root->right);
      }
      void correctBST(Node* root) {
          first=prev=temp=second=NULL;
          inorder(root);
          second==NULL?swap(first->data,temp->data):swap(first->data,second->data);
      }
  };