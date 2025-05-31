// #Question:-

// Link-> https://leetcode.com/problems/snakes-and-ladders/description/?envType=daily-question&envId=2025-05-31

// Date-> 31/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getCoordinates(int label, int n) {
        // this will give number to {r,c} mapping of board of 1->n^2
        int r = n - 1 - (label - 1) / n;
        int c = (label - 1) % n;
        if ((n - 1 - r) % 2 == 1) {
            c = n - 1 - c;
        }
        return {r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) break;

                auto [r, c] = getCoordinates(next, n);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }

                if (next == n * n) return moves + 1;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};
// 