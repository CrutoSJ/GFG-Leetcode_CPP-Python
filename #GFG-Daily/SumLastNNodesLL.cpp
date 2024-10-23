// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1

// Date-> 23/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        int len = 0, ctr = 0, sum = 0;
        struct Node* temp = head;
        while(temp){
            len++;
            temp=temp->next;
        }
        temp = head;
        while(temp){
            ctr++;
            if(len-ctr<n){
                sum += temp->data;
            }
            temp=temp->next;
        }
        return sum;
        
    }
};