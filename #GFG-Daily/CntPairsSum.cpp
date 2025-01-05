// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1

// Date-> 05/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countPairs(vector<int> &arr, int target) {
        int cnt=0;
        sort(arr.begin(), arr.end());
        int low=0, high=arr.size()-1;
        
        while(low<high){
            int sum = arr[low]+arr[high];
            
            if(sum<target){
                cnt+=high-low;
                low++;
            } else{
                high--;
            }
        }
        return cnt;
    }
};