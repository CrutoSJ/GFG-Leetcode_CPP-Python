// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<vector<int>> ans;
    vector<int> answer;
    if(root == nullptr){
    return {};
}

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        
        for(int i=0; i<size; i++){
            Node* to = q.front();
            q.pop();
            level.push_back(to->data);
            if(to->left!=nullptr){
                q.push(to->left);
            }
            if(to->right!=nullptr){
                q.push(to->right);
            }
        }
        ans.push_back(level);
    }
    
    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            answer.push_back(ans[i][j]);
        }
    }
return answer; 
}