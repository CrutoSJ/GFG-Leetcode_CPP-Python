// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1

// Date-> 31/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* prev, *next;
};

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node* newNode = new Node();
        newNode->data = x;
        if(head->data > x){
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = NULL;
            return newNode;
        }
        Node* temp = head;
        Node* last = NULL;
        while(temp!= NULL){
            if(temp->data > x){
                newNode ->next =temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                return head;
            }
            last = temp;
            temp = temp->next;
        }
        last->next = newNode;
        newNode->prev = last;
        newNode->next = NULL;
        return head;
    }
};