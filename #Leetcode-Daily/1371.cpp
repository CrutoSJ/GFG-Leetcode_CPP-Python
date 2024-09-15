// #Question:-

// Link-> https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

// Date-> 15/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> map;

        int mask = 0;
        map[mask] = -1;

        int result = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a'){
                mask = (mask ^ (1 << 0));
            } else if(s[i] == 'e'){
                mask = (mask ^ (1 << 1));
            } else if(s[i] == 'i'){
                mask = (mask ^ (1 << 2));
            } else if(s[i] == 'o'){
                mask = (mask ^ (1 << 3));
            } else if(s[i] == 'u'){
                mask = (mask ^ (1 << 4));
            }

            if(map.find(mask) != map.end()){
                result = max(result, i - map[mask]);
            } else{
                map[mask] = i;
            }
        }

        return result;
    }
};