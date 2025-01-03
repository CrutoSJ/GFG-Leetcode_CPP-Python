// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

// Date-> 03/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int curXor=0, cnt=0;
        unordered_map<int,int> mp;
        
        for(int &x:arr){
            curXor^=x;
            if(curXor==k)cnt++;
            cnt+=mp[curXor^k];
            mp[curXor]++;
        }
        return cnt;
    }
};