// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

// Date-> 17/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        int n = parent.size();
        vector<Node*> nodes;
        Node* root = NULL;
        
        for(int i=0; i<n; i++){
            Node* temp = new Node(i);
            nodes.push_back(temp);
        }
        
        for(int i=0; i<n ;i++){
            if(parent[i] == -1){
                root = nodes[i];
            }
            else if(nodes[parent[i]]->left == NULL){
                nodes[parent[i]]->left = nodes[i];
            }
            else{
                nodes[parent[i]]->right = nodes[i];
            }
        }
        return root;
    }
};