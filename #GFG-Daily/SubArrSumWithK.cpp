// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

// Date-> 02/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int currSum=0, cnt=0;
        unordered_map<int,int> mp;
        for(int x:arr){
            currSum += x;
            if(currSum==k)cnt++;
            cnt+=mp[currSum-k];
            mp[currSum]++;
        }
        return cnt;
    }
};