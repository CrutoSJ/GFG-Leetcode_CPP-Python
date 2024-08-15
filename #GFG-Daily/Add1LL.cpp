// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// Date-> 15/08/24

// #Solution:-

#include <bits/stdc++.h>
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
private:
    Node* reverseList(Node* head){
        Node* prvs = NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* nxt = curr->next;
            curr->next = prvs;
            prvs = curr;
            curr = nxt;
        }
        return prvs;
    }
public:
    Node* addOne(Node* head) {
        head = reverseList(head);
        
        Node* temp = head;
        int carry = 1;
        while(temp!=NULL){
            int val = temp->data+carry;
            if(val<10){
                temp->data = val;
                carry=0;
                break;
            }
            carry=1;
            temp->data = 0;
            temp = temp->next;
        }
        
        if(carry == 1){
            Node* newNode = new Node(1);
            head = reverseList(head);
            newNode->next = head;
            return newNode;
        }
        
        head = reverseList(head);
        return head;
    
    }
};