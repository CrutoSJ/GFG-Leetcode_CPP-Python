// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

// Date-> 01/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class solution {
  public:
    long long MOD = 10e8+7;
    
    long long multiplyTwoLists(Node *first, Node *second) {
        long long val1 = 0;
        long long val2 = 0;
        
        Node* temp1 = first;
        Node* temp2 = second;
        
        while(temp1!=NULL){
            val1 = ((val1*10) + temp1->data)%MOD;
            temp1 = temp1->next;
        }
        
        while(temp2 != NULL){
            val2 = ((val2*10) + temp2->data)%MOD;
            temp2 = temp2->next;
        }
        
        return (val1*val2)%MOD;
    }
};