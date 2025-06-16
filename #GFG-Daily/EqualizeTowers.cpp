// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1

// Date-> 16/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isTrue(vector<int>& heights, vector<int>& cost, int mid, int n){
        int midCost  = 0;
        int mid1Cost = 0;
        
        for(int i=0; i<n; i++){
            midCost  += (abs(heights[i] - mid) * cost[i]);
            mid1Cost += (abs(heights[i] - (mid+1)) * cost[i]);
        }
        
        return midCost < mid1Cost;
    }
    
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        int l = *min_element(heights.begin(), heights.end());
        int h = *max_element(heights.begin(), heights.end());
        int resultH = -1;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(isTrue(heights, cost, mid, n)){
                resultH = mid;
                h = mid-1;
            } else{
                l = mid+1;
            }
        }
        
        long long res = 0;
        
        for(int i=0; i<n; i++){
            res += (long long)(abs(heights[i] - resultH) * cost[i]);
        }
        
        return (int)res;
    }
};
