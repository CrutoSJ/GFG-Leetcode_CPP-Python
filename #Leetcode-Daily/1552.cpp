// #Question:-

// Link-> https://leetcode.com/problems/magnetic-force-between-two-balls/

// Date-> 20/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& position, int m, int mid){
        int prev = position[0];
        int cnt  = 1;
        
        for(int i=1; i<position.size(); i++){
            if(position[i]-prev >= mid){
                cnt++;
                prev=position[i];
            }
            
            if(cnt == m) break;
        }
        
        return cnt == m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        
        int s=1;
        int e=position[n-1]-position[0];
        
        int ans=INT_MIN;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(isPossible(position, m, mid)){
                ans=mid;
                s=mid+1;
            } else{
                e=mid-1;
            }
        }
        return ans;
    }
};