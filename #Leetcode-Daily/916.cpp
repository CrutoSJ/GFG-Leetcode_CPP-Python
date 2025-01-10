// #Question:-

// Link-> https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10

// Date-> 10/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        vector<int> req(26,0);

        for(auto s : words2){
            vector<int> temp(26,0);
            for(auto c : s) temp[c-'a']++;
            for(int i=0;i<26;i++) req[i] = max(req[i],temp[i]);
        }

        for(auto s : words1){
            vector<int> mp(26,0);
            for(auto c : s) mp[c-'a']++;
            int flag = 0;
            for(int i=0;i<26;i++){
                if(mp[i]<req[i]){
                    flag=1;
                    break;
                }
            }
            if(!flag) ans.push_back(s);
        }
        return ans;
    }
};