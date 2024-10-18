// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/single-number1014/1

// Date-> 18/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int num = 0;
        for(auto &x : arr){
            num ^= x;
        }
        return num;
    }
};