// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

// Date-> 06/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
public:

    void populateNext(Node *root) {
        Node* prev = NULL;
        Node* cr = NULL;
        Node* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                Node* pred = curr->left;
                while(pred->right && pred->right != curr){
                    pred=pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr=curr->left;
                } else{
                    pred->right = NULL;
                    if(cr == NULL){
                        cr=curr;
                    } else{
                        prev = cr;
                        cr=curr;
                        prev->next = cr;
                    }
                    curr=curr->right;
                }
            } 
            else{
                if(cr == NULL){
                    cr=curr;
                } else{
                    prev=cr;
                    cr=curr;
                    prev->next=cr;
                }
                curr=curr->right;
            }
        }
    }
};