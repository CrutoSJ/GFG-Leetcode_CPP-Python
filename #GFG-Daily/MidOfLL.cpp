// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

// Date-> 12/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        if(head == NULL){
            return -1;
        }
        Node* fast = head;
        Node* slow = head;
        while(fast->next!= NULL){
            fast = fast->next;
            if(fast->next!=NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow->data;
    }
};