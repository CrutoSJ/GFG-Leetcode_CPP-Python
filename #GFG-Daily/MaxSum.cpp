// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

// Date-> 07/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long max_sum(int a[], int n) {
        long long temp=0, sum=0, ans=0;
        for(long long i=0; i<n; i++){
            temp+=i*a[i];
            sum+=a[i];
        }
        ans=temp;
        for(long long i=1; i<n; i++){
            temp=temp-sum + (long long)a[i-1]*n;
            ans=max(ans,temp);
        }
        return ans;
    }
};
