// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1

// Date-> 26/10/24

// #Solution:-

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
    int count(struct Node* head, int key) {
        int cnt = 0;
        struct Node* temp = head;
        while(temp){
            if(temp->data == key)cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};