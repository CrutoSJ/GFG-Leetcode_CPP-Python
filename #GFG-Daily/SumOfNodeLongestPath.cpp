// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

// Date-> 29/05/25

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
    pair<int,int> solve(Node* root){
        if(root == NULL){
            return {0,0};
        }
        
        if(root->left == NULL && root->right == NULL){
            return {1, root->data};
        }
        
        pair<int,int> left  = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        priority_queue<pair<int,int>> pq;
        pq.push(left);
        pq.push(right);
        
        auto top = pq.top();
        int len = top.first+1;
        int sum = top.second+root->data;
        
        return {len, sum};
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        pair<int,int> ans;
        ans = solve(root);
        return ans.second; 
    }
};