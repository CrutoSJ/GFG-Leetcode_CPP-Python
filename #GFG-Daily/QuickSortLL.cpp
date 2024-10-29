// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

// Date-> 29/10/24

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
  public:
    static void solve(struct Node *pivot, Node *&left, Node *&right){
        Node* temp = pivot->next;
        while(temp){
            Node* nxt=temp->next;
            if(temp->data <= pivot->data){
                temp->next=left;
                left=temp;
            }else{
                temp->next=right;
                right=temp;
            }
            temp=nxt;
        }
    }
    
    struct Node* quickSort(struct Node* head) {
        if(!head || !head->next){
            return head;
        }
        Node* left = NULL, *right = NULL;
        solve(head, left, right);
        left  = quickSort(left);
        right = quickSort(right);
        Node* traversal = left;
        while(traversal and traversal->next) traversal =traversal->next;
        if(traversal)traversal->next=head;
        else left=head;
        head->next=right;
        return left;
    }
};