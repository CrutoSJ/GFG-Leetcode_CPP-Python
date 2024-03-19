#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int i = 0 , j = 0;
        int sum = 0;
        
        while(j < n){
            sum += arr[j];
            
            while(sum > s){
                sum-=arr[i];
                i++;
            }
            
            if(sum == s && i <= j){
                return {i+1 , j+1};
            }
            j++;
        }
        return {-1};
    }
};