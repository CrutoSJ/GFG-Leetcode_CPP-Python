// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

// Date-> 20/01/25

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
    Node* sortedMerge(Node* head1, Node* head2) {
        
        Node *start=NULL;
        Node *tail=NULL;
        if(head1->data<=head2->data){
            start=head1;
            head1=head1->next;
        }
        else{
            start=head2;
            head2=head2->next;
        }
        tail=start;
        while(head1 && head2){
            if(head1->data<=head2->data){
                tail->next=head1;
                head1=head1->next;
                
            }
            else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        
        
        if(head1){
            tail->next=head1;
        }
        else{
            tail->next=head2;
        }
        return start;
    }
};