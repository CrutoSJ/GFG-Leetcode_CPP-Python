// #Question:-

// Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

// Link-> https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

// #SOlution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(K==1){
            return NULL;
        }
        Node *temp = head;
        int count = 1;
        while(temp && temp->next){
          
          if(count == K-1){
              temp->next=temp->next->next;
              count = 0;
          }
          
          else{
              temp = temp->next;
              count++;
          }
      }
      return head;
    }
};