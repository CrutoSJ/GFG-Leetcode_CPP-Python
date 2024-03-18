// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/level-order-traversal/1

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

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      vector<int>v;
      queue<Node*>q;
      if(root==NULL){
          return v;
      }
      q.push(root);
      while(!q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
              Node* update_node=q.front();
              q.pop();
              if(update_node->left!=NULL){
                  q.push(update_node->left);
              }
              if(update_node->right!=NULL){
                  q.push(update_node->right);
              }
              
              v.push_back(update_node->data);
          }
      }
      return v;
    }
};