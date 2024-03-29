// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        map<int,int>mpp;
        mpp[0]=1;
        int prevsum = 0;
        int cnt = 0;
        for(int i=0; i<N;i++){
            prevsum += Arr[i];
            int rem = prevsum-k;
            cnt+=mpp[rem];
            mpp[prevsum] += 1;
        }
        
        return cnt;
    }
};