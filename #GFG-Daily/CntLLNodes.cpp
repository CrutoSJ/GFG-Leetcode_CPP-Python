// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

// Date-> 14/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int len = 0;
        Node* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len += 1;
        }
        return len;
    }
};