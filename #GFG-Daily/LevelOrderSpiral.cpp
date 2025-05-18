// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

// Date-> 18/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        int level = 0;
        queue<Node*>q;
        vector<int> ans;
        int index = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans.resize(ans.size()+size);
            for(int i =0;i<size;i++){
                if(level%2!=0){
                    Node*temp=q.front();
                    q.pop();
                    ans[index++]=temp->data;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                else{
                    Node*temp=q.front();
                    q.pop();
                    ans[ans.size()-i-1]=temp->data;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            level++;
            index = ans.size();
        }
        return ans;
    }
};