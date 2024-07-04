// #Question:-

// Link-> https://leetcode.com/problems/merge-nodes-in-between-zeros/

// Date-> 04/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int sum){
        ListNode* temp = new ListNode(sum);
        if(head==NULL){
            head = temp;
            tail = temp;
            return ;
        } else{
            tail->next = temp;
            tail = temp;
        }
    }
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int sum = 0;
        while(temp!=NULL){
            if(temp->val==0){
                insertAtTail(ansHead, ansTail, sum);
                sum = 0;
            }
            else if(temp->val!=0){
                sum += temp->val;
            }
            temp = temp->next;
        }
        return ansHead;
    }
};