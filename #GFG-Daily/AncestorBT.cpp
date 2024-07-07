// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1

// Date-> 07/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
public:
    bool solve(vector<int>& ans, struct Node *root, int target){
        if(root==NULL){
            return false;
        }
        
        if(root->data == target){
            return true;
        }
        
        if(solve(ans, root->left, target) || solve(ans, root->right, target)){
            ans.push_back(root->data);
            return true;
        }
        return false;
    }
    
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int>ans;
        solve(ans, root, target);
        return ans;
    }
};