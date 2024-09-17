// #Question:-

// Link-> https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17

// Date-> 17/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        unordered_map<string, int> freq;

        for(int i=0; i<s1.length(); i++){
            string word = "";
            while(i<s1.length() && s1[i] != ' '){
                word += s1[i];
                i++;
            }
            freq[word]++;
        }

        for(int i=0; i<s2.length(); i++){
            string word = "";
            while(i<s2.length() && s2[i] != ' '){
                word += s2[i];
                i++;
            }
            freq[word]++;
        }

        for(auto &val : freq){
            if(val.second == 1){
                result.push_back(val.first);
            }
        }

        return result;
    }
};