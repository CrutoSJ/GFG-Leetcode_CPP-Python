// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/you-and-your-books/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        long long sum = 0, value = 0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k){
                sum+=arr[i];
            }
            else{
                value = max(sum,value);
                sum = 0;
            }
        }
        
        value = max(sum,value);
        
        return value;
    }
};