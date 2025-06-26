// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/game-with-string4100/1

// Date-> 26/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        vector<int> freq(26, 0);
        
        for(auto &ch : s){
            freq[ch - 'a']++;
        }
        
        priority_queue<int> pq;
        
        for(auto &it : freq){
            if(it != 0){
                pq.push(it);
            }
        }
        
        while(k--){
            if(!pq.empty()){
                int top = pq.top();
                pq.pop();
                pq.push(top-1);
            }
        }
        
        int sum = 0;
        
        while(!pq.empty()){
            int top = pq.top();
            sum += (top*top);
            pq.pop();
        }
        
        return sum;
    }
};