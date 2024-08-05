// #Question:-

// Link-> https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05

// Date-> 05/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans = "";
        unordered_map<string, int> mp;
        
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        vector<string> unique;
        for(const string &s : arr){
            if(mp[s] == 1){
                unique.push_back(s);
            }
        }

        if(k > unique.size()){
            return ans;
        }

        ans = unique[k-1];
        return ans;
    }
};