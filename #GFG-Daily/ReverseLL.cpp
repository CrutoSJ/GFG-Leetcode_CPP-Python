// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

// Date-> 18/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
    private:
        void solve(Node* &head, Node* curr, Node* prvs){
            if(curr==NULL){
                head = prvs;
                return ;
            }
            
            Node* forward = curr->next;
            solve(head, forward, curr);
            curr->next = prvs;
        }
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *curr = head;
        Node *prvs = NULL;
        solve(head, curr, prvs);
        return head;
    }
    
};