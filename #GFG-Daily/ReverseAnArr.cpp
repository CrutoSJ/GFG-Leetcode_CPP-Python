// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/reverse-an-array/1

// Date-> 17/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int s = 0;
        int e = arr.size()-1;
        
        while(s<=e){
            swap(arr[s], arr[e]);
            s++, e--;
        }
    }
};