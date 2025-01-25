// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

// Date-> 25/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        Node* slow=head;
        Node* fast=head;
        
        while(slow && fast){
            slow=slow->next;
            fast=fast->next;
            if(fast)fast=fast->next;
            if(slow==fast) break;
        }
        
        if(fast!=slow || slow==NULL || fast==NULL)return NULL;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};