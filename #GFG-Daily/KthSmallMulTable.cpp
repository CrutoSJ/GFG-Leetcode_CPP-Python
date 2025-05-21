// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

// Date-> 21/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int lessThanK(int n, int mid, int m){
        int sum=0;
        for(int i=1; i<=m; i++){
            sum+=min(mid/i, n);
        }
        return sum;
    }
  public:
    int kthSmallest(int m, int n, int k) {
        int l=1;
        int h=m*n;
        
        while(l<=h){
            int mid = (l+h)/2;
            
            if(lessThanK(n, mid, m)<k){
                l=mid+1;
            } else{
                h=mid-1;
            }
        }
        return l;
    }
};