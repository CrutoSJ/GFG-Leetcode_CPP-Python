// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/alternative-sorting1311/1

// Date-> 25/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> res(n,-1);
        int i=0, j=n-1, idx=0;
        
        while(i<=j){
            res[idx] = arr[j];
            idx++, j--;
            res[idx] = arr[i];
            idx++, i++;
        }
        
        return res;
    }
};