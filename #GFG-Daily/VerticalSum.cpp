// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/vertical-sum/1

// Date - 05/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node *left,*right;
};

class Solution{
public:
    map<int,int>mp;
    void solve(Node * root, int pos)
    {
        if(!root)
        return;
        
        mp[pos] += root->data;
        solve(root->left,pos-1);
        solve(root->right,pos+1);
    }
    vector <int> verticalSum(Node *root) {
        solve(root,0);
        vector<int> res;
        for(auto it : mp)
        res.push_back(it.second);
        return res;
    }
};