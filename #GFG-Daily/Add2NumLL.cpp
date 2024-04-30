// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

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

class Solution
{
    private:
    void removeStrtZ(struct Node* &a){
        struct Node* temp = a;
        while(temp && temp->data==0){
            temp=temp->next;
        }
        a = temp;
    }
    
    struct Node* revList(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int sum){
        Node* temp = new Node(sum);
        
        if(head == NULL){
            head = temp;
            tail = temp;
            return ;
        }
        
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL && second != NULL){
            int sum = carry + first->data + second->data;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            
            first = first->next;
            second = second->next;
        }
        
        while(first != NULL){
            int sum = carry + first->data;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            
            first = first->next;
        }
        
        while(second != NULL){
            int sum = carry + second->data;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            
            second = second->next;
        }
        
        while(carry != 0){
            int sum = carry;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
        }
        
        return ansHead;
        
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        removeStrtZ(num1);
        removeStrtZ(num2);
        
        if(!num1 and !num2){
            struct Node* p = new Node(0);
            return p;
        }
        if(!num2){
            return num1;
        }
        if(!num1){
            return num2;
        }
        
        Node* first = revList(num1);
        Node* second = revList(num2);
        
        Node* ans = add(first, second);
        
        ans = revList(ans);
        
        return ans;
    }
};