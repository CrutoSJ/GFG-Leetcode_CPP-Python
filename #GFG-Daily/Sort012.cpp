// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// Date-> 09/09/24 & 05/12/24 & 29/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++,mid++;
            } else if(arr[mid]==1){
                mid++;
            } else if(arr[mid]==2){
                swap(arr[mid], arr[high]);
                high--;
            }
        }
        return ;
    }
};