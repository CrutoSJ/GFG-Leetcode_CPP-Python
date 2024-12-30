// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

// Date-> 30/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;
        for(auto &x:a){
            st.insert(x);
        }
        
        for(auto &x:b){
            st.insert(x);
        }
        
        return st.size();
    }
};