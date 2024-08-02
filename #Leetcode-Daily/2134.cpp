// #Question:-

// Link-> https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02

// Date-> 02/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int i=0, j=0;
        int maxOnes = 0;
        int currOnes = 0;
        while(j<2*n){
            if(nums[j%n] == 1){
                currOnes++;
            }

            if(j-i+1 > totalOnes){
                currOnes -= nums[i%n];
                i++;
            }

            maxOnes = max(maxOnes, currOnes);
            j++;
        }
        return totalOnes-maxOnes;
    }
};