// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// Date-> 07/08/24

// #Solutin:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        if(k==n+m) return max(arr1[n-1],arr2[m-1]);
        if(k==1) return min(arr1[0], arr2[0]);
        int i=0, j=0;
        
        while(i<n && j<m && k>1){
            if(arr1[i] <= arr2[j]){
                i++;
            } else{
                j++;
            }
            k--;
        }
        
        while(i<n && k>1){
            i++;
            k--;
        }
        
        while(j<m && k>1){
            j++;
            k--;
        }
        if(i==n) return arr2[j];
        else if(j==m) return arr1[i];
        return min(arr1[i], arr2[j]);
    }
};