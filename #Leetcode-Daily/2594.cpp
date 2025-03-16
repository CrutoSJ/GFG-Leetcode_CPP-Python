// #Question:-

// Link-> https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16

// Date-> 16/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        typedef long long ll; 
        bool isPossible(ll mid, vector<int> &ranks, int &cars){
            ll cnt=0;
            for(int i=0; i<ranks.size(); i++){
                cnt += sqrt(mid/ranks[i]);
                if(cnt>=cars)return true;
            }
            return cnt>=cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            ll l = 1;
            int maxE = *max_element(ranks.begin(), ranks.end()) ;
            ll r = 1LL * maxE * cars * cars;
            ll res=-1;
    
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(isPossible(mid,ranks,cars)){
                    res=mid;
                    r=mid-1;
                } else{
                    l=mid+1;
                }
            }
            return res;
        }
    };