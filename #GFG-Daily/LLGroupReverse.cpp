// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

// Date-> 21/01/25

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

    }*head;

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(head==NULL){
            return head;
        }
        
        struct Node* prvs=NULL;
        struct Node* curr=head;
        struct Node* next=NULL;
        
        int count = 0;
        
        while(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prvs;
            prvs = curr;
            curr = next;
            count++;
        }
        
        if(next != NULL){
            head -> next = reverseKGroup(next, k);
        }
        
        return prvs;
    }
};