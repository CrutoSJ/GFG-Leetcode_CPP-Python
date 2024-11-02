// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/kth-distance3757/1

// Date-> 02/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int i=0, j=0;
        while(i<n && j<n){
            if(freq[arr[j]] > 0){
                return true; 
            } else if(j-i >= k){
                freq[arr[i]]--;
                i++;
            } else {
                freq[arr[j]]++;
                j++;
            } 
        }
        return false;
    }
};