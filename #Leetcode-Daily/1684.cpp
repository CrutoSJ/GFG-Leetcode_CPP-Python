// #Question:-

// Link-> https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=daily-question&envId=2024-09-12

// Date-> 12/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> map;
        for(auto &x : allowed){
            map[x] = true;
        }
        int count = 0;
        for(int i=0; i<words.size(); i++){
            bool flag = false;
            for(auto &ch : words[i]){
                if(map.find(ch) == map.end()){
                    flag = true;
                }
            }
            if(flag == false){
                count++;
            }
        }
        return count;
    }
};