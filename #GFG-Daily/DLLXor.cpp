// #Question :-

// Link-> https://www.geeksforgeeks.org/problems/xor-linked-list/1

// Date-> 07/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

struct Node *insert(struct Node *head, int data) {
    Node* temp = new Node(data);
    temp->npx  = head;
    if(head){
        head->npx = XOR(temp, head->npx);
    }
    return temp;
}

vector<int> getList(struct Node *head) {
    vector<int> ans;
    Node* curr = head, *prev = NULL, *nxt = NULL;
    while(curr){
        ans.push_back(curr->data);
        nxt = XOR(prev, curr->npx);
        prev = curr;
        curr = nxt;
    }
    return ans;
}