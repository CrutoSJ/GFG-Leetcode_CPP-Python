// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1

// Date-> 17/10/24

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

class Solution {
  public:
    void insertAtEnd(struct Node* &head, struct Node* &tail, int data){
        if(head == NULL){
            struct Node* temp = new Node(data);
            head = temp;
            tail = head;
            return;
        }
        tail->next = new Node(data);
        tail = tail->next;
    }
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        struct Node* temp  = head;
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* head2 = NULL;
        struct Node* tail2 = NULL;
        int i = 0;
        
        while(temp){
            if(i%2 == 0){
                insertAtEnd(head1, tail1, temp->data);
            } else{
                insertAtEnd(head2, tail2, temp->data);
            }
            temp=temp->next;
            i++;
        }
        
        return {head1, head2};
        
        
    }
};