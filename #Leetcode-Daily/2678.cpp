// #Question:-

// Link-> https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01

// Date-> 01/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i=0; i<details.size(); i++){
            int age = ((details[i][11] - '0') * 10) +  (details[i][12] - '0');
            if(age >= 61){
                cnt++;
            }
        }
        return cnt;
    }
};