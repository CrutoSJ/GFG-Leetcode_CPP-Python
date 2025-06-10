// #Question:-

// Link-> https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-question&envId=2025-06-10

// Date-> 10/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        for(char &ch : s){
            freq[ch]++;
        }

        int maxOdd = 0, minEven = INT_MAX;

        for(auto &it : freq){
            if(it.second % 2 == 0){
                minEven = min(minEven, it.second);
            } else{
                maxOdd = max(maxOdd, it.second);
            }
        }
        return maxOdd - minEven;
    }
};