// #Question:-

// Link->   https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30

// Date-> 30/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> lastind(26,-1);
            int i,n = s.length(),j,mx;
            for(i = 0; i < n; i++){
                lastind[s[i]-'a'] = i;
            }
            vector<int> ans;
            i = 0, j = 0;
            while(i<n){
                mx = lastind[s[i]-'a'];
                j = i;
                while(j<=mx){
                    mx = max(mx,lastind[s[j]-'a']);
                    j++;
                }
                ans.push_back(j-i);
                i = j;
            }
            return ans;
        }
    };