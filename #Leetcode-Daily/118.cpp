// #Question:-

// Date-> 01/08/25

// Link-> https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2025-08-01

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<int> generateRow(int row){
    vector<int>ansRow;
    long long ans = 1;
    ansRow.push_back(1);
    for(int col = 1; col<row; col++){
        ans = ans * (row-col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};