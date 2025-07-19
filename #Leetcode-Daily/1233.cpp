// #Question:-

// Link-> https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25

// Date-> 25/10/24 && 19/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        unordered_map<string, bool> mp;
        sort(folder.begin(), folder.end(), [](const string &a, const string &b){
            return a.size()<b.size();
        });

        for(int i=0; i<folder.size(); i++){
            string ch = "";
            bool flag = true;
            for(int j=0; j<folder[i].size(); j++){
                if(folder[i][j] == '/' && mp.find(ch) != mp.end()){
                    flag = false;
                    break;
                }
                ch += folder[i][j];
            }
            if(flag && mp.find(ch) == mp.end()){
                mp.insert({ch,true});
            }
        }

        for(auto &x : mp){
            res.push_back(x.first);
        }
        return res;
    }
};