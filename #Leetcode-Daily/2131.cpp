// #Question:-

// Link-> https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-25

// Date-> 25/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        int res=0;
        unordered_map<string, int> mp;

        for(string &word : words){
            string temp = word;
            swap(temp[0], temp[1]);

            if(mp.find(temp) != mp.end()){
                res+=4;
                mp[temp]--;
                if(mp[temp]==0){
                    mp.erase(temp);
                }
            } else{
                mp[word]++;
            }
        }

        for(auto &it : mp){
            string word = it.first;
            int cnt  = it.second;

            if(word[0] == word[1] && cnt>0){
                res+=2;
                break;
            }
        }
        return res;
    }
};