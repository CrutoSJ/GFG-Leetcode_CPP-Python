// #Question:-

// Link-> https://leetcode.com/problems/letter-tile-possibilities/description/?envType=daily-question&envId=2025-02-17

// Date-> 17/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(string &tiles, string &curr, vector<bool> &used, unordered_set<string> &res)
    {
        res.insert(curr);

        for (int i = 0; i < n; i++)
        {
            if (used[i])
                continue;

            used[i] = true;
            curr.push_back(tiles[i]);

            solve(tiles, curr, used, res);

            used[i] = false;
            curr.pop_back();
        }
    }

public:
    int n;
    int numTilePossibilities(string tiles)
    {
        n = tiles.length();
        unordered_set<string> res;
        vector<bool> used(n, false);
        string curr = "";
        solve(tiles, curr, used, res);

        return res.size() - 1;
    }
};

// 2nd solution :-

class Solution2
{
private:
    void solve(vector<int> &vec)
    {
        cnt++;

        for (int i = 0; i < 26; i++)
        {
            if (vec[i] == 0)
                continue;
            vec[i]--;
            solve(vec);
            vec[i]++;
        }
    }

public:
    int cnt;
    int numTilePossibilities(string tiles)
    {
        cnt = 0;
        vector<int> vec(26, 0);
        for (auto &ch : tiles)
        {
            vec[ch - 'A']++;
        }

        solve(vec);

        return cnt - 1;
    }
};