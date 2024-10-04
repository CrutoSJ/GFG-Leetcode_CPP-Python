// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

// Date-> 04/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node* curr = head->next;
        Node* prvs = head;
        Node* next = NULL;
        
        while(curr != head){
            next = curr->next;
            curr->next = prvs;
            prvs = curr;
            curr = next;
        }
        curr->next = prvs;
        return prvs;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node* temp = head->next;
        Node* prvs = head;
        
        if(head->data == key){
            while(temp != head){
                prvs = temp;
                temp = temp->next;
            }
        } else{
            while(temp != head && temp->data != key){
                prvs = temp;
                temp = temp->next;
            }
        }
        
        if(head->data == key || temp != head){
            prvs->next = temp->next;
        }
        
        return head->data == key ? prvs->next : head;
    }
};