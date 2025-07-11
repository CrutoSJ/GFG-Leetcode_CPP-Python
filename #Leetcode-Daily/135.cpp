// #Question:-

// Link-> https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2025-06-02

// Date-> 02/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;

        int i=1;

        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candies += peak;
                i++;

                if(i == n){
                    return candies;
                }
            }

            int dip=0;
            while(i<n && ratings[i] < ratings[i-1]){
                dip++;
                candies += dip;
                i++;
            }

            candies -= min(peak, dip);
        }
        return candies;
    }
};