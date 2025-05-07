// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

// Date-> 06/05/25

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
      vector<int> leftView(Node *root) {
          vector<int> result;
          if (!root) return result;
          
          queue<Node*>q;
          q.push(root);
          
          while(!q.empty()){
              
              int n=q.size();
              Node* curr = q.front();
              result.push_back(curr->data);
              
              while(n--){
                  Node* x = q.front();
                  q.pop();
                  if(x->left)
                  q.push(x->left);
                  if(x->right)
                  q.push(x->right);
              }
          }
          return result;
      }
  };