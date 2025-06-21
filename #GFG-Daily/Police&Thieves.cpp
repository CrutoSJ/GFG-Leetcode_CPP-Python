// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1

// Date-> 21/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        
        int i=0, j=0;
        int cnt = 0;
        
        while(i<n && j<n){
            while(i<n && arr[i] != 'P') i++;
            while(j<n && arr[j] != 'T') j++;
            
            if(i>=n || j>=n) break;
            
            if(abs(i-j) <= k){
                cnt++;
                i++, j++;
            } else{
                if(i>j) j++;
                else if(j>i) i++;
            }
        }
        return cnt;
    }
};