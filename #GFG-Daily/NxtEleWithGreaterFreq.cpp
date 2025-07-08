// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1

// Date-> 08/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> freq;
        for(int& num: arr) {
            freq[num]++;
        }
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && freq[arr[st.top()]]<=freq[arr[i]]) {
                st.pop();
            }
            if(st.empty()) result[i]=-1;
            else result[i]=arr[st.top()];
            st.push(i);
        }
        return result;
    }
};
