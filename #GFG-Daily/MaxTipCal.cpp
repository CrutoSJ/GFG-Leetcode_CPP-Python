// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1

// Date- 11/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int,int>> tips;
        for(int i=0; i<n; i++){
            tips.push_back({arr[i]-brr[i],i});
        }
        
        sort(tips.begin(), tips.end(), [](pair<int,int>&a, pair<int,int>&b) {
            return abs(a.first) > abs(b.first);
        });
        
        long long sum=0;
        int countA=0, countB=0;
        
        for(auto &tip: tips){
            int diff = tip.first;
            int index = tip.second;
            
            if((diff>0 && countA<x) || countB>=y){
                sum+=arr[index];
                countA++;
            } else{
                sum+=brr[index];
                countB++;
            }
        }
        return sum;
    }
};
