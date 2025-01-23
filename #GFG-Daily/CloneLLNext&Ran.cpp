// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

// Date-> 23/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  private: 
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        
        tail->next=temp;
        tail=temp;
    }
  public:
    Node *cloneLinkedList(Node *head) {
        //step 1: create clone list of next pointer in original list
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp=temp->next;
        }
        
        //step 2-> insert clone node between original nodes list
        Node* originalNode = head;
        Node* cloneNode    = cloneHead;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* temp         = originalNode->next;
            originalNode->next = cloneNode;
            originalNode       = temp;
            
            temp               = cloneNode->next;
            cloneNode->next    = originalNode;
            cloneNode          = temp;
        }
        
        //step 3 -> pointing to random pointers in clone list
        temp = head;
        
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random = (temp->random == NULL ? temp->random : temp->random->next);
            }
            temp = temp->next->next;
        }
        
        //step 4 -> undo step 2, i.e remove faltu pointers (zig zag wale)
        
        originalNode = head;
        cloneNode    = cloneHead;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next = cloneNode->next;
            originalNode       = originalNode->next;
            
            if(originalNode!=NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        
        //step 5->return cloneHead;
        return cloneHead;
    }
};