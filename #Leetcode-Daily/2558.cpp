// #Question:-

// Link-> https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12

// Date-> 12/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res=0;
        priority_queue<int> pq;

        for(int &gift : gifts){
            pq.push(gift);
        }

        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(floor(top)));
        }

        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};