// #Question:-

// Link-> https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/?envType=daily-question&envId=2025-01-26

// Date-> 26/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
    private:
        Node* isPresent(Node* head){
            if(head == NULL){
                return NULL;
            }
            
            Node* slow = head;
            Node* fast = head;
            
            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
                
                if(slow == fast){
                    return slow;
                }
            }
            
            return NULL;
        }
        
        Node* startPos(Node* head){
            if(head == NULL){
                return NULL;
            }
            
            Node* temp = isPresent(head);
            Node* slow = head;
            
            while(slow != temp){
                slow = slow->next;
                temp = temp->next;
            }
            
            return slow;
        }
        
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head == NULL){
            return ;
        }
        
        if(isPresent(head) == NULL){
            return ;
        }
        
        Node* posNode = startPos(head);
        Node* temp = posNode;
        
        while(temp-> next != posNode ){
            temp = temp->next;
        }
        
        temp -> next = NULL;

        
    }
};