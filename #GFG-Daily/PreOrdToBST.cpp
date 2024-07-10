// #Question:-

// Link-> https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

BinaryTreeNode* toBST(vector<int> preorder, int s, int e){//Method 1 -> through sorting so it becomes inorder, and then making BST
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    BinaryTreeNode* temp = new BinaryTreeNode(preorder[mid]);
    temp->left = toBST(preorder, s, mid-1);
    temp->right = toBST(preorder, mid+1, e);
    return temp;
}

BinaryTreeNode* preorderToBST(vector<int> &preorder) {//Method 1 -> through sorting so it becomes inorder, and then making BST
    sort(preorder.begin(), preorder.end());
    return toBST(preorder, 0, preorder.size()-1);
}

// Method 2 -> using the property of preorder, and inserting only if lies in the provided range , O(3N) TC i.e O(N)

BinaryTreeNode*  solve(vector<int> preorder, int mini, int maxi, int&i){// Method 2 -> using the property of preorder, and inserting only if lies in the provided range , O(3N) TC i.e O(N)
    if(i>=preorder.size()){
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }

    BinaryTreeNode* temp = new BinaryTreeNode(preorder[i++]);
    temp->left = solve(preorder, mini, temp->data, i);
    temp->right = solve(preorder, temp->data, maxi, i);
    return temp;
}

BinaryTreeNode* preorderToBST2(vector<int> &preorder) {// Method 2 -> using the property of preorder, and inserting only if lies in the provided range , O(3N) TC i.e O(N)
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i=0;
    BinaryTreeNode* ans = solve(preorder, mini, maxi, i);
    return ans;
}