// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

// Date-> 24/01/25

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
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        Node* slow=head;
        Node* fast=head->next;
        
        while(slow!=NULL && fast!=NULL){
            if(slow==fast) return true;
            slow=slow->next;
            fast=fast->next;
            if(fast)fast=fast->next;
        }
        
        return false;
    }
};