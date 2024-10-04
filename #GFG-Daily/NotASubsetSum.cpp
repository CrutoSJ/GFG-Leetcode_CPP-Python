// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1

// Date-> 05/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        long long ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > (ans+1)){
                return ans+1;
            }
            ans += arr[i];
        }
        
        return ans+1;
    }
};