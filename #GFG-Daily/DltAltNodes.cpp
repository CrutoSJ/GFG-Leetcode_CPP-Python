// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1

// Date-> 13/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = NULL;
    }
};

class Solution {
  public:
    void solve(struct Node *head){
        Node* temp = head;
        
        while(temp->next != NULL){
            temp->next = temp->next->next;
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
    }
    
    void deleteAlt(struct Node *head) {
        if(head == NULL || head->next == NULL){
            return ;
        }
        
        return solve(head);
    }
};