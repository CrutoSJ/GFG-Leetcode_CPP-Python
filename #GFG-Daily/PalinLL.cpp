// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// Date-> 25/09/24

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

class Solution{
  private:
    Node* findMiddle(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* temp){
        Node* curr = temp;
        Node* prvs = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prvs;
            prvs = curr;
            curr = next;
        }
        
        return prvs;
    }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next == NULL){
            return true;
        }
        
        Node* middle = findMiddle(head);
        
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        Node* head1 = head;
        Node* head2 = middle->next;
        
        while(head2 != NULL){
            if(head1->data != head2->data){
                return 0;
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        temp = middle->next;
        middle->next = reverse(temp);
        
        return 1;
    }
};