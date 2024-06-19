// #Question:-

// Link-> https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

//Date -> 19/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int> bloomDay, int mid, int m, int k){
        int count = 0;
        int sum = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
            }
            else{
                sum += (count/k);
                count = 0;
            }
        }
        sum += (count/k);
        
        if(sum>=m){
            return true;
        }
        else{
            return false;
        }
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int total = m*1LL * k*1LL;
        
        if(total > bloomDay.size()){
            return -1;
        }
        
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isPossible(bloomDay, mid, m, k)){
                e = mid-1;
            }
            
            else {
                s = mid+1;
            }
        }
        
        return s;
    }
};