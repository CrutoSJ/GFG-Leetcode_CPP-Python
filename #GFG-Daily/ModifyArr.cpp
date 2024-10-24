// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/ease-the-array0633/1

// Date-> 24/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i]==arr[i-1] && arr[i] != 0){
                arr[i-1] *= 2;
                arr[i] = 0;
            }
        }

        vector<int> res(n,0);
        int idx=0;
        for(auto &x : arr){
            if(x != 0){
                res[idx] = x;
                idx++;
            }
        }
        
        return res;
    }
};