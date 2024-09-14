// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

// Date-> 04/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> pos;
        vector<int> neg;
        for(auto &val : arr){
            if(val<0){
                neg.push_back(val);
            } else{
                pos.push_back(val);
            }
        }
        
        int i=0, j=0;
        int idx = 0;
        
        while(i<pos.size() && j<neg.size()){
            arr[idx++] = pos[i++];
            arr[idx++] = neg[j++];
        }
        
        while(i<pos.size()){
            arr[idx++] = pos[i++];
        }
        while(j<neg.size()){
            arr[idx++] = neg[j++];
        }
    }
};