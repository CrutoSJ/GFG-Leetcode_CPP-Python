// #Question:-

// Link -> https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14

// Date -> 14/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPossible(vector<int> &candies, int mid, long long k){
            int n=candies.size();
    
            for(int i=0; i<n; i++){
                k-=candies[i]/mid;
                if(k<=0){
                    return true;
                }
            }
            return k<=0;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            long long candieSum = accumulate(candies.begin(), candies.end(), 0LL);
            int maxCandie = *max_element(candies.begin(), candies.end());
    
            if(candieSum<k)return 0;
    
            int l=1, r=maxCandie;
            int res = 0;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(isPossible(candies, mid, k)){
                    res = mid;
                    l=mid+1;
                } else{
                    r=mid-1;
                }
            }
            return res;
        }
    };