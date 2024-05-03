// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/k-distance-from-root/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    // function should print the nodes at k distance from root
    void func(Node* root, int level, vector<int> &store, int k)
    {
        if(!root) return;
        if(level==k) store.push_back(root->data);
        func(root->left, level+1, store, k);
        func(root->right, level+1, store, k);
    }
    
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> store;
        func(root, 0, store, k);
        return store;
    }
};
