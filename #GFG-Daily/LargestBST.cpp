// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/largest-bst/1

// Date-> 22/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};



class Solution{
    public:
    info solve(Node* root, int &ans){
    if(root==NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    info currNode;
    
    currNode.size = left.size+right.size+1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    
    if((left.isBST) && (right.isBST) && ((root->data > left.maxi) && (root->data < right.mini))){
        currNode.isBST = true;
    } else{
        currNode.isBST = false;
    }
    
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    
    return currNode;
}
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	int maxSize = 0;
    	info ans = solve(root, maxSize);
    	return maxSize;
    }
};