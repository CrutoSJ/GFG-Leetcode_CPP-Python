// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

// Date-> 26/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    private:
      int CntNodes(struct Node* root){
          if(root == NULL){
              return 0;
          }
          
          int left = CntNodes(root->left);
          int right = CntNodes(root->right);
          int ans = left+right+1;
          return ans;
      }
      
      bool isCmplt(struct Node* root, int nodes, int i){
          if(root==NULL){
              return true;
          }
          
          if(i>nodes){
              return false;
          }
          
          int left = 2*i;
          int right = 2*i+1;
          
          bool leftT = isCmplt(root->left, nodes, left);
          bool rightT = isCmplt(root->right, nodes, right);
          
          return leftT&&rightT;
          
      }
      
      bool isMaxOrd(struct Node* root){
          if(root->left == NULL && root->right == NULL){
              return true;
          }
          
          if(root->right == NULL){
              if(root->data > root->left->data){
                  return true;
              } else{
                  return false;
              }
          }
          
          else{
              bool left = isMaxOrd(root->left);
              bool right = isMaxOrd(root->right);
              return (left && right && ((root->data > root->left->data) && (root->data > root->right->data)));
          }
      }
      
    public:
      bool isHeap(struct Node* tree) {
          int nodes = CntNodes(tree);
          if(isCmplt(tree, nodes, 1) && isMaxOrd(tree)){
              return true;
          } else{
              return false;
          }
      }
  };