// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1

// Date -> 19/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        sort(arr, arr+n);
        int s=0;
        int e=n-1;
        int ans = INT_MIN;
        int dif = INT_MAX;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(arr[mid] == k){
                return arr[mid];
            }
            
            else if(arr[mid] > k ){
                if(arr[mid]-k <= dif){
                    dif = arr[mid]-k;
                    ans = arr[mid];
                }
                e = mid-1;
            }
            
            else{
                if(k-arr[mid] < dif){
                    dif = k-arr[mid];
                    ans = arr[mid];
                }
                s = mid+1;
            }
        }
        
        return ans;
    } 
};