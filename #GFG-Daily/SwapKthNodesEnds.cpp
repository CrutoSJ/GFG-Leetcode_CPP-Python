// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1

// Date-> 02/09/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        Node* start=head;
        int len=0;
        while(start){
            len++;
            start=start->next;
        }
        
        if(k>len)return head;
        int s=k;
        int e=len-k+1;
        if(e==s)return head;
        
        start=head;
        int idx=1;
        Node* point1;
        Node* point2;
        while(start){
            if(idx==s)point1=start;
            else if(idx==e)point2=start;
            start=start->next;
            idx++;
        }
        
        int temp=point1->data;
        point1->data=point2->data;
        point2->data=temp;
        return head;
    }
};
