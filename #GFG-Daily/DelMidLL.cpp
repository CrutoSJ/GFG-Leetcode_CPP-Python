// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        if(head==NULL || head->next == NULL){
            return NULL;
        }
        
        Node* fast = head;
        Node* slow = head;
        Node* prev = head;
        
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
            }
            
            if(slow!=head){
                prev = prev->next;
            }
            
            slow = slow->next;
        }
        
        prev->next = slow->next;
        
        return head;
    }
};