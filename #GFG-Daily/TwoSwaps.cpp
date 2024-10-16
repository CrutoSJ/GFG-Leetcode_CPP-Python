// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/two-swaps--155623/1

// Date-> 16/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int i=0;
        int cnt=0;
        while(i<arr.size()){
            if(arr[i] != i+1){
                swap(arr[i], arr[arr[i]-1]);
                cnt++;
            } else{
                i++;
            }
        }
        return cnt==0 || cnt==2 ? true : false;
    }
};

