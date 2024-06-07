// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1

// Date - 07/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOccured(int n, int l[], int r[], int maxx) {

        vector<int>arr(maxx+2,0);
        for(int i=0; i<n; i++){
            arr[l[i]]++;
            arr[r[i]+1]--;
        }
        int sum=0;
        for(int i=0; i<maxx+2; i++){
            arr[i]+=sum;
            sum=arr[i];
        }
        int ans=0;
        for(int i=0; i<maxx+2; i++){
            if(arr[i]>arr[ans]) ans = i;
        }
        return ans;
    }
};