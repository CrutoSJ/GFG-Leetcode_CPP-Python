// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1

// Date-> 03/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

class Solution {
public:
    Node* removeAllDuplicates(struct Node* head) {
        Node* temp = head;
        Node* prvs = NULL;
        while(temp!=NULL){
            int cnt=0;
            while(temp!= NULL && temp->next!=NULL){
                if(temp->data == temp->next->data){
                    temp=temp->next;
                    cnt++;
                } else{
                    break;
                }
            }
            if(cnt>0){
                if(prvs!= NULL){
                    prvs->next=temp->next;
                    temp=prvs->next;
                } else{
                    head=temp->next;
                    temp=head;//bcz we'll check from start again..
                }
            } else{
                prvs=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};