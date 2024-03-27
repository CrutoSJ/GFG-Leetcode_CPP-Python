// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1?page=1&sortBy=submissions

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int start = -1, end = n ;
        long long s1 = 0,s2 = 0;
        while(end - start > 2) {
            if(s1<s2)s1+=a[++start];
            else s2 += a[--end];
        }
        if(s1 == s2)return start+2;
        else return -1;
    }

};