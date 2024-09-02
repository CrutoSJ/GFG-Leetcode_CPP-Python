// #Question:-

// Link->  https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02

// Date-> 02/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;

        int i=0;
        while(k >= chalk[i]){
            k -= chalk[i];
            i++;
        }
        return i;
    }
};