// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

//Date -> 01-05-24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        struct Node* vowel = new Node(-1);
        struct Node* conso = new Node(-1);
        struct Node* vow = vowel;
        struct Node* con = conso;
        
        while(head != NULL){
            if(head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u'){
                vowel->next = new Node(head->data);
                vowel = vowel->next;
            }
            
            else{
                conso->next = new Node(head->data);
                conso = conso->next;
            }
            
            head = head->next;
        }
        
        vowel->next = con->next;
        return (vow->next);
    }
};