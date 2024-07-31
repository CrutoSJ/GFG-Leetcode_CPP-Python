// #Question:-

// Link-> https://leetcode.com/problems/filling-bookcase-shelves/description/?envType=daily-question&envId=2024-07-31

// Date-> 31/07/24 

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int WIDTH;
    int t[1001][1001];

    int solve(vector<vector<int>> &books, int i, int leftW, int maxH){
        if(i >= n){
            return maxH;
        }

        if(t[i][leftW] != -1){
            return t[i][leftW];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        //keep
        if(bookW <= leftW){
            keep = solve(books, i+1, leftW - bookW, max(maxH, bookH));
        }

        //keep
        skip = maxH + solve(books, i+1, WIDTH - bookW, bookH);

        return t[i][leftW] =  min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        WIDTH = shelfWidth;
        memset(t, -1, sizeof(t));

        int leftW = shelfWidth;

        return solve(books, 0, leftW, 0);
    }
};