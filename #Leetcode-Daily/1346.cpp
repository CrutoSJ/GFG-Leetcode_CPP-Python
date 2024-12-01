// #Question:-

// Link-> https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01

// Date-> 01/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> st;

        for(int i=0; i<n; i++){
            st[arr[i]] = i;
        }

        for(int i=0; i<n; i++){
            if(st.find(2*arr[i]) != st.end() && i!= st[2*arr[i]]){
                return true;
            }
        }

        return false;
    }
};