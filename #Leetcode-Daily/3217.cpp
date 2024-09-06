// #Question:-

// Link-> https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06

// Date-> 06/09/24

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        while(s.find(head->val) != s.end()){
            head = head->next;
        }

        ListNode* temp = head;
        ListNode* prvs = NULL;

        while(temp!=NULL){
            if(s.find(temp->val) != s.end()){
                temp=temp->next;
                prvs->next=temp;
            } else{
                prvs=temp;
                temp=temp->next;
            }
        }

        return head;
    }
};