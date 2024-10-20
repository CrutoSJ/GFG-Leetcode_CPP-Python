// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1

// Date-> 20/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        DLLNode *head1 = head;
        DLLNode *head2 = head;
        
        while(head1!=NULL){
            pq.push(head1->data);
            if(pq.size() == k+1){
                head2->data = pq.top();
                head2=head2->next;
                pq.pop();
            }
            head1=head1->next;
        }
        
        while(!pq.empty()){
            head2->data=pq.top();
            head2=head2->next;
            pq.pop();
        }
        
        return head;
    }
};