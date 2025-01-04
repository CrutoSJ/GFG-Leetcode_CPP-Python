// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1

// Date-> 04/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countTriplets(vector<int> &arr, int target) {
        int cnt=0;
        int n  =arr.size();
        for(int i=0; i<=n; i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>target)k--;
                else if(sum<target)j++;
                else if(sum==target){
                    cnt++;
                    int temp = j+1;
                    while(temp<k && arr[temp]==arr[temp-1]){
                        cnt++,temp++;
                    }
                    k--;
                }
            }
        }
        return cnt;
    }
};