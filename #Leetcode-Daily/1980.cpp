// #Question:-

// Link-> https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20

// Date-> 20/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        unordered_set<string> numsSet;
        
        string generate(string curr) {
            if (curr.size() == n) {
                if (numsSet.find(curr) == numsSet.end()) {
                    return curr;
                }
                
                return "";
            }
            
            string addZero = generate(curr + "0");
            if (addZero.size() > 0) {
                return addZero;
            }
            
            return generate(curr + "1");
        }
        
        string findDifferentBinaryString(vector<string>& nums) {
            n = nums.size();
            for (string s : nums) {
                numsSet.insert(s);
            }
            
            return generate("");
        }
    };