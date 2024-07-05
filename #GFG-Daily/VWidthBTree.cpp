// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

// Date-> 05/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int maxi = INT_MIN;
    int mini = INT_MAX;
    // Function to find the vertical width of a Binary Tree.
    void solve(Node* root, int idx){
        if(root == NULL){
            return ;
        }
        
        maxi = max(maxi,idx);
        mini = min(mini,idx);
        
        solve(root->left, idx-1);
        solve(root->right, idx+1);
        return ;
    }
    int verticalWidth(Node* root) {
        if(root == NULL) return 0;
        solve(root, 0);
        return maxi + abs(mini) + 1;
    }
};