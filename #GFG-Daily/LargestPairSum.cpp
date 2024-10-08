// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/pair-sum--120604/1

// Date-> 08/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        
        for(auto &val : arr){
            if(val>maxi2){
                maxi2 = val;
                if(maxi2>maxi1){
                    swap(maxi1,maxi2);
                }
            }
        }
        return maxi1+maxi2;
    }
};