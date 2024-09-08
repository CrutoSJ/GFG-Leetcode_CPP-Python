// #Question:-

// Link-> https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08

// Date-> 09/09/24

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
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int L = 0;
        while(curr){
            L++;
            curr=curr->next;
        }

        int size  = L/k;
        int extra = L%k;

        curr = head;
        ListNode* prvs = NULL;

        vector<ListNode*> result(k, NULL);

        for(int i=0; i<k; i++){
            result[i] = curr;

            for(int cnt=1; cnt <= size + (extra > 0 ? 1 : 0); cnt++){
                prvs = curr;
                curr = curr->next;
            }

            if(prvs!=NULL){
                prvs->next=NULL;
            }
            extra--;
        }

        return result;
    }
};