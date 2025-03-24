// #Question:-

// Link-> https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24

// Date-> 24/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int n=meetings.size();
            int res=0;
            int start=0, end=0;
    
            sort(meetings.begin(), meetings.end());
    
            for(auto &meet : meetings){
                if(meet[0]>end){
                    res += meet[0]-end-1;
                }
                end = max(end,meet[1]);
            }
            if(end<days){
                res += days-end;
            }
            return res;
        }
    };