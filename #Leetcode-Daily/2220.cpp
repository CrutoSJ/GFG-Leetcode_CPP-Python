// #Question:-

// Link-> https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11

// Date-> 11/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toBin(int num){
        if (num == 0) return "0";
        string ans = "";
        while(num>0){
            int rem = num%2;
            num /= 2;
            ans.push_back(rem + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int minBitFlips(int start, int goal) {
        string num1 = toBin(start);
        string num2 = toBin(goal);

        int i = num1.size();
        int j = num2.size();

        if(i<j){
            num1 = string(j-i, '0') + num1;
        } else{
            num2 = string(i-j, '0') + num2;
        }

        int cnt = 0;

        for(int i=0; i<num1.size(); i++){
            if(num1[i] != num2[i]){
                cnt++;
            }
        }
        
        return cnt;
    }
};