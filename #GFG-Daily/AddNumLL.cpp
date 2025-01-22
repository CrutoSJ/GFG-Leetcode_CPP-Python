// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

// Date-> 22/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    void removeZ(Node* &a){
        Node* temp = a;
        
        while(temp!= NULL && temp->data==0){
            temp=temp->next;
        }
        
        a = temp;
    }
    
    struct Node* reverseL(Node* num){
        Node* curr = num;
        Node* prvs = NULL;
        Node* next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prvs;
            prvs = curr;
            curr = next;
        }
        
        return prvs;
    }
    
    void insertAtTail(Node* &head, Node* &tail, int sum){
        Node* temp = new Node(sum);
        
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        
        tail->next=temp;
        tail=temp;
    }
    
    Node* add(Node* first, Node* second){
        int carry = 0;
        Node* head = NULL;
        Node* tail = NULL;
        
        while(first && second){
            int sum = carry+first->data+second->data;
            int digit = sum%10;
            insertAtTail(head,tail,digit);
            carry = sum/10;
            
            first=first->next;
            second=second->next;
        }
        
        while(first){
            int sum = carry+first->data;
            int digit = sum%10;
            insertAtTail(head,tail,digit);
            carry = sum/10;
            
            first=first->next;
        }
        
        while(second){
            int sum = carry+second->data;
            int digit = sum%10;
            insertAtTail(head,tail,digit);
            carry = sum/10;
            
            second=second->next;
        }
        
        while(carry!=0){
            int sum = carry;
            int digit = sum%10;
            insertAtTail(head,tail,digit);
            carry = sum/10;
        }
        
        return head;
    }
    
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        removeZ(num1);
        removeZ(num2);
        
        if(!num1 && !num2){
            Node* res = new Node(0);
            return res;
        }
        
        if(!num1){
            return num2;
        }
        
        if(!num2){
            return num1;
        }
        
        Node* first  = reverseL(num1);
        Node* second = reverseL(num2);
        
        Node* res = add(first,second);
        res = reverseL(res);
        
        return res;
    }
};