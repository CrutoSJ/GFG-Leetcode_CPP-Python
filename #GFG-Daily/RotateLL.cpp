// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

// Date-> 19/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        
        int len=1;
        Node* length = head;
        
        while(length->next!=NULL){
            length=length->next;
            len++;
        }
        
        k=k%len;
        if(k==0){
            return head;
        }
        
        Node* temp = head;
        while(k>1){
            temp=temp->next;
            k--;
        }
        
        Node* newHead = temp->next;
        temp->next = NULL;
        
        length->next = head;
        
        return newHead;
    }
};
