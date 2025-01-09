// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

// Date-> 09/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class SOlution{
    public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n=arr.size(), j=0, sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            while(sum>target && j<i)sum-=arr[j++];
            if(sum==target) return {j+1,i+1};
        }
        return {-1};
    }
};