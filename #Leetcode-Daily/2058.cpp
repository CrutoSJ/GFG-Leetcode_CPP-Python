// #Question:-

// Link-> https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int val = head->val, cnt = 2;
        vector<int>crc;
        ListNode* temp = head->next;
        while(temp->next!=NULL){
            int curr = temp->val;
            int nxt = temp->next->val;
            if(((curr > val) && (curr > nxt)) || ((curr < val) && (curr < nxt))){
                crc.push_back(cnt);
            }
            cnt++;
            val = temp->val;
            temp=temp->next; 
        }
        vector<int> ans(2);
        if(crc.size() <= 1){
            ans[0] = -1;
            ans[1] = -1;
        } else {
            int n = crc.size()-1;
            int mini = INT_MAX;
            for(int i=1; i<=n; i++){
                mini = min(mini, crc[i]-crc[i-1]);
            }
            ans[0] = mini;
            ans[1] = (crc[n]-crc[0]);
        }
        return ans;
    }
};