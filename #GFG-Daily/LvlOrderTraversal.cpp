// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/level-order-traversal/1

// Date-> 02/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution
{
    public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> lvl;
        vector<int> temp;
        queue<Node *> qu;
        qu.push(root);
        int count = 0, l = 0;
        while(!qu.empty()){
            Node* ele = qu.front();
            qu.pop();
            temp.push_back(ele->data);
            if(count == pow(2, l) || qu.empty()){
                lvl.push_back(temp);
                temp.clear();
                l++;
            }
            count++;
            if(ele->left){
                qu.push(ele->left);
            } 
            if(ele->right){
                qu.push(ele->right);
            }
        }
        
        return lvl;
    }
};