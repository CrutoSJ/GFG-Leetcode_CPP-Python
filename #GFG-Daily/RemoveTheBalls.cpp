// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1

// Date-> 11/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        int n = color.size();
        stack<pair<int,int>> st;
        
        for(int i=0; i<n; i++){
            if(!st.empty()){
                auto top = st.top();
                int clr = top.first;
                int rad = top.second;
                if(clr == color[i] && rad == radius[i]){
                    st.pop();
                } else{
                    st.push({color[i], radius[i]});
                }
            } else{
                st.push({color[i], radius[i]});
            }
        }
        return st.size();
    }
};