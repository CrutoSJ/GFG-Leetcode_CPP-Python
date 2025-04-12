// #Question:-

// Link-> https://leetcode.com/problems/find-the-count-of-good-integers/?envType=daily-question&envId=2025-04-12

// Date-> 12/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string> dict;
            int base = pow(10, (n - 1) / 2);
            int skip = n & 1;
            for (int i = base; i < base * 10; i++) {
                string s = to_string(i);
                s += string(s.rbegin() + skip, s.rend());
                long long palindromicInteger = stoll(s);
                if (palindromicInteger % k == 0) {
                    sort(s.begin(), s.end());
                    dict.emplace(s);
                }
            }
    
            vector<long long> factorial(n + 1, 1);
            long long ans = 0;
            for (int i = 1; i <= n; i++) {
                factorial[i] = factorial[i - 1] * i;
            }
            for (const string &s : dict) {
                vector<int> cnt(10);
                for (char c : s) {
                    cnt[c - '0']++;
                }
                long long tot = (n - cnt[0]) * factorial[n - 1];
                for (int x : cnt) {
                    tot /= factorial[x];
                }
                ans += tot;
            }
    
            return ans;
        }
    };