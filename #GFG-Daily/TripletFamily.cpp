// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/triplet-family/1

// Date-> 27/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=n-1; i>=2; i--){
            int target = arr[i];
            int e=i-1;
            int s=0;
            while(s<e){
                if(target == (arr[s]+arr[e])){
                    return true;
                } else if(target<(arr[s] + arr[e])){
                    e--;
                } else{
                    s++;
                }
            }
        }
        return false;
    }
};