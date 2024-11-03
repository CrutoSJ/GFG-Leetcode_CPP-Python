// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1

// Date-> 03/11/24

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
    bool isLengthEven(struct Node **head) {
        struct Node *temp = *head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len%2==0;
    }
};