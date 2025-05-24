// #Question:-

// Link-> https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24

// Date-> 24/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>ans;
        for(int i = 0;i<n;i++){
            for(auto a:words[i]){
                if(a==x){
                ans.push_back(i);
                break;
                }
            }    
        }
        return ans;
    }
};