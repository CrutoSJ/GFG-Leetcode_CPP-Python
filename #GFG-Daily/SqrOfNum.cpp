// #Question:-

// Link-> https://www.geeksforgeeks.org/problem-of-the-day?utm_source=gfgpractice&utm_medium=events_page&utm_campaign=events_series_problem_of_the_day

// Date-> 13/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int floorSqrt(long long int n) {
        if(n==0 || n==1){
            return n;
        }
        
        long long int s=1, e=n, ans=-1;
        while(s<=e){
            long long int mid = s+ (e-s)/2;
            
            if(mid*mid == n){
                return mid;
            }
            
            else if(mid*mid < n){
                ans = mid;
                s = mid+1;
            }
            
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};