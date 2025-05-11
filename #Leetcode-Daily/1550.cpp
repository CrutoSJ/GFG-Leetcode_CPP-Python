// #Question:-

// Link-> https://leetcode.com/problems/three-consecutive-odds/submissions/1631195483/?envType=daily-question&envId=2025-05-11

// Date-> 11/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]%2 != 0){
                cnt++;
            } else{
                cnt = 0;
            }
            if(cnt == 3){
                return true;
            }
        }
        return false;
    }
};