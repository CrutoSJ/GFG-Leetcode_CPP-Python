// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-numbers-containing-specific-digits/1

// Date-> 20/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        int tWays = 9 * pow(10, n-1);
        int m = 10 - arr.size();
        int unwanted = pow(m,n);
        if(find(arr.begin(), arr.end(), 0) == arr.end()){
            unwanted -= pow(m,n-1);
        }
        return tWays - unwanted;
    }
};
