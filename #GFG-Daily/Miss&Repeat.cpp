// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// Date-> 23/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        
        for(int i=0; i<n; i++){
            int num = abs(arr[i]);
            if(arr[num-1]<0){
                res.push_back(num);
            } else{
                arr[num-1] *= -1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]>0){
                res.push_back(i+1);
            }
        }
        
        return res;
    }
};