// #Question:-

// Link-> https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/submissions/1670626038/?envType=daily-question&envId=2025-06-20

// Date-> 20/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        int maxMD = 0;

        for(int i=0; i<n; i++){
            if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;

            int steps = i+1;

            int currMD = abs(east-west) + abs(north-south);
            int wasted  = steps - currMD;

            int extra = 0;
            if(wasted != 0){
                extra = min(2*k, wasted);
            }

            int finalCurrMD = currMD + extra;

            maxMD = max(maxMD, finalCurrMD);
        }
        return maxMD;
    }
};