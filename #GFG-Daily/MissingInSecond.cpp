// #Question:-

// #Link - https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

// Given two integer arrays a of size n and b of size m, the task is to find the numbers which are present in the first array a, but not present in the second 
// array b.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;
class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    map<int,int>mpp;
        vector<int> res;
        for(int i=0;i<m;i++){
            mpp[b[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[a[i]]==0){ 
                res.push_back(a[i]);
            }
        }
        return res;
	} 
};