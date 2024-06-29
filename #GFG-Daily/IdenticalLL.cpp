// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/identical-linked-lists/1

// Date-> 29/06/24

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

bool areIdentical(struct Node *head1, struct Node *head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1 != NULL || temp2 != NULL) return false;
    return true;
}

