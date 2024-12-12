// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

// Date-> 12/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        int stIdx=-1, enIdx=-1;
        
        for(int i=0; i<2; i++){
            int start = 0, end = n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(arr[mid] == target){
                    if(i==0){
                        stIdx=mid;
                        end=mid-1;
                    } else{
                        enIdx=mid;
                        start=mid+1;
                    }
                } else if(arr[mid] > target){
                    end = mid-1;
                } else{
                    start=mid+1;
                }
            }
        }
        return stIdx==-1 ? 0 : enIdx-stIdx+1;
    }
};