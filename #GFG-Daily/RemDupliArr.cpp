// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1

// Date-> 28/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        set<int> st;
        for(auto x = arr.begin(); x != arr.end();){
            if(st.find(*x) != st.end()){
                x = arr.erase(x);
            } else{
                st.insert(*x);
                ++x;
            }
        }
        return arr;
    }
};