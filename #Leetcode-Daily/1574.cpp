// #Question:-

// Link-> https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/?envType=daily-question&envId=2024-11-15

// Date-> 15/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i=0, j=n-1;

        while(j>0 && arr[j]>=arr[j-1]){
            j--;
        }

        int res = j;

        while(i<j && (i==0 || arr[i]>= arr[i-1])){
            while(j<n && arr[i]>arr[j]){
                j++;
            }

            res = min(res, j-i-1);
            i++;
        }

        return res;
    }
};