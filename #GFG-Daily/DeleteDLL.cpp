// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if(x==1){
            return head->next;
        }
        int cnt = 1;
        Node* temp = head;
        while(cnt<x){
            temp=temp->next;
            cnt+=1;
        }
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        return head;
    }
};
