// #Question:-

// Link-> https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21

// Date-> 21/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int curr, int n, vector<int> &result){
        if(curr>n){
            return ;
        }

        result.push_back(curr);

        for(int append=0; append<=9; append++){
            int newNum = (curr*10) + append;

            if(newNum>n){
                return ;
            }

            solve(newNum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int startNum = 1; startNum<=9; startNum++){
            solve(startNum, n, result);
        }

        return result;
    }
};