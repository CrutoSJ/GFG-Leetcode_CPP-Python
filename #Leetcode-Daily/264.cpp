// #Question:-

// Link-> https://leetcode.com/problems/ugly-number-ii/description/?envType=daily-question&envId=2024-08-18

// Date-> 18/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1){
            return 1;
        }
        vector<int> dp(n);
        dp[0] = 1;

        int i2=0, i3=0, i5=0;
        int MTwo   = 2;
        int MThree = 3;
        int MFive  = 5;

        for(int i=1; i<n; i++){
            int ugly = min({MTwo, MThree, MFive});
            dp[i] = ugly;

            if(ugly == MTwo){
                i2++;
                MTwo = dp[i2] * 2;
            }

            if(ugly == MThree){
                i3++;
                MThree = dp[i3] * 3;
            }

            if(ugly == MFive){
                i5++;
                MFive = dp[i5] * 5;
            }
        }
        return dp[n-1];
    }
};