// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/array-to-bst4443/1

// Date-> 25/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

class Solution {
private:
    Node* arrToBST(vector<int>& nums, int s, int e, Node* root){
        
        if(s>e){
            return NULL;
        }
        
        int mid = s+(e-s)/2;
        
        root = new Node(nums[mid]);
        
        root->left = arrToBST(nums, s, mid-1, root);
        root->right = arrToBST(nums, mid+1, e, root);
        
        return root;
    }
    
public:
    Node* sortedArrayToBST(vector<int>& nums) {
        Node* root = NULL;
        int s=0, e=nums.size()-1;
        return arrToBST(nums, s, e, root);
    }
};