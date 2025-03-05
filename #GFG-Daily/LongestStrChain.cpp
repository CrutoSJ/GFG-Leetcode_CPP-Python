// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/longest-string-chain/1

// Date -> 05/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestStringChain(vector<string> &words)
    {
        int maxL = 1;
        unordered_map<string, int> mp;

        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        for (auto &word : words)
        {
            int length = 1;
            for (int i = 0; i < word.size(); i++)
            {
                string temp = word.substr(0, i) + word.substr(i + 1);
                if (mp.find(temp) != mp.end())
                {
                    length = max(length, (mp[temp] + 1));
                }
                mp[word] = length;
            }
            maxL = max(maxL, length);
        }
        return maxL;
    }
};