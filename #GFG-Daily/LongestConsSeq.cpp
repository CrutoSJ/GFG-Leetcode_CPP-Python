// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// Date-> 31/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int ans=1;
        unordered_map<int,int> map;
        for(int &x:arr){
            if(!map[x]){
                int left  = map[x-1];
                int right = map[x+1];
                int total = left+right+1;
                map[x]    = total;
                map[x-left]  = total;
                map[x+right] = total;
                ans = max(ans,total);
            }
        }
        return ans;
    }
};