// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

// Date-> 13/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0, mid=0, high=n-1;
        while(low<high){
            mid = low + (high-low)/2;
            if(arr[mid]<=arr[high])high=mid;
            else low=mid+1;
        }
        return arr[low];
    }
};