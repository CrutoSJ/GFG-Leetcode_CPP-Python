// #Question:-

// Link-> https://leetcode.com/problems/max-chunks-to-make-sorted/description/?envType=daily-question&envId=2024-12-19

// Date-> 19/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int res=0, maxEle=0;

        for(int i=0; i<n; i++){
            maxEle = max(maxEle, arr[i]);
            if(maxEle==i){
                res++;
            }
        }
        return res;
    }
};