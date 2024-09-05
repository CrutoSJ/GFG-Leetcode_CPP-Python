// #Question:-

// Link-> 

// Date-> 05/09/24

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> solve(int x, int n){
        if(x<n || x>6*n){
            return {};
        }

        vector<int> result (n,1);
        x -= n;

        for(int i=0; i<n && x>0; i++){
            int add = min(5,x);
            result[i] += add;
            x -= add;
        }

        return result;
    }
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int s   = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);

        int misSum = (mean*(s+n)) - sum;

        vector<int> nums = solve(misSum, n);
        return nums;
    }
};