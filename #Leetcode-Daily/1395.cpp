// #Question:-

// Link-> https://leetcode.com/problems/count-number-of-teams/?envType=daily-question&envId=2024-07-29

// Date-> 29/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        for(int j=1; j<n-1; j++){

            int leftSmallCnt = 0;
            int leftLargCnt = 0;
            int rightSmallCnt = 0;
            int rightLargCnt = 0;

            for(int i=0; i<j; i++){
                if(rating[i] < rating[j]){
                    leftSmallCnt++;
                } else if(rating[i] > rating[j]){
                    leftLargCnt++;
                }
            }
            
            for(int k=j+1; k<n; k++){
                if(rating[k] < rating[j]){
                    rightSmallCnt++;
                } else if(rating[k] > rating[j]){
                    rightLargCnt++;
                }
            }

            teams +=  (leftSmallCnt*rightLargCnt) + (rightSmallCnt*leftLargCnt);

        }
        return teams;
    }
};