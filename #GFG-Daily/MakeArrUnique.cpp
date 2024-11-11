// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1

// Date-> 11/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_set<int> st;
        st.insert(arr[0]);
        int cnt = 0;
        
        for(int i=1; i<n; i++){
            if(st.find(arr[i]) != st.end()){
                int inc = abs(arr[i]-arr[i-1])+1;
                arr[i] += inc;
                cnt += inc;
            }
            st.insert(arr[i]);
        }
        return cnt;
    }
};