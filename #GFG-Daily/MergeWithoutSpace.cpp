// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// Date-> 11/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=0;
        
        while(i>=0 && j<m){
            if(a[i]<=b[j]){
                break;
            } else{
                swap(a[i--],b[j++]);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};