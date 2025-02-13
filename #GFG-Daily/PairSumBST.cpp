// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

// Date-> 13/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    void solve(Node* root, int target, set<int> &st, bool &ans){
        
        // base case 
        if(root == NULL) return;
        if(ans == true) return;
        
        
        solve(root->left, target, st, ans);
        solve(root->right, target, st, ans);
        
        int diff = target - root->data;
        if(st.count(diff)) ans = true;
        st.insert(root->data);
    }
    
    bool findTarget(Node *root, int target) {
        set<int> st;
        bool ans = false;
        solve(root, target, st, ans);
        return ans;  
    }
};