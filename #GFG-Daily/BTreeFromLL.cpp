// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/make-binary-tree/1

// Date-> 01/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    TreeNode* solve(vector<int>& arr, int i){
        if(i>=arr.size()){
            return NULL;
        }
        
        TreeNode* node = new TreeNode(arr[i]);
        node->left = solve(arr,2*i+1);
        node->right = solve(arr,2*i+2);
        return node;
    }
public:
    void convert(Node *head, TreeNode *&root) {
        Node* temp = head;
        vector<int>arr;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        root=solve(arr,0);
    }
};