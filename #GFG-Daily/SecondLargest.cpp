// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/second-largest3735/1

// Date-> 15/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int mini1 = INT_MIN;
        int mini2 = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>mini2 && arr[i]!=mini1){
                mini2 = arr[i];
                if(mini2>mini1){
                    swap(mini1,mini2);
                }
            }
        }
        
        if(mini1==mini2 || mini2==INT_MIN){
            return -1;
        }
        return mini2;
    }
};