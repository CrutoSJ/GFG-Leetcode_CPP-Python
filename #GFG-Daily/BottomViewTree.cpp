// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Date-> 05/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            Node* frontNode = front.first;
            int hd = front.second;
            
            mp[hd] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        
        for(auto &i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};