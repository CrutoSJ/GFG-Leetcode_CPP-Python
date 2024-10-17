// #Question:-

// Link-> https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17

// Date-> 17/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> vec(10, -1);

        for(int i=0; i<str.size(); i++){
            int idx = str[i]-'0';
            vec[idx] = i;
        }

        for(int i=0; i<str.size(); i++){
            char currC = str[i];
            int  currD = currC - '0';

            for(int digit=9; digit>currD; digit--){
                if(vec[digit]>i){
                    swap(str[i], str[vec[digit]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};