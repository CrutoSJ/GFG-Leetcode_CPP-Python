// #Question:-

// Link-> https://leetcode.com/problems/minimum-increment-to-make-array-unique/

// Date-> 14/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        vector<int>count(nums.size()+max,0);
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        int moves=0;
        for(int i=0; i<count.size(); i++){
            while(count[i]>1){
                int j=i+1;
                while(j<count.size() && count[j]!=0){
                    j++;
                }
                if(j<count.size()){
                    count[j]=1;
                }
                count[i]--;
                moves+=(j-i);
            }
        }
        return moves;
    }
};