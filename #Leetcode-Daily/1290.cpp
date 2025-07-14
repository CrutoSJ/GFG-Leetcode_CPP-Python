// #Question:-

// Link-> https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14

// Date-> 14/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            ans*=2;
            ans+=(temp->val);
            temp=temp->next;
        }
        return ans;
    }
};
