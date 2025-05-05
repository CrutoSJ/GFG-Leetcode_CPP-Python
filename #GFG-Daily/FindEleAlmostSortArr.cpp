// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

// Date-> 05/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          int n=arr.size();
          int start=0,end=n-1;
          int mid=start+(end-start)/2;
          
          while(start<=end){
              if(arr[mid]==target){
                  return mid;
              }
              
              if(mid>start && arr[mid-1]==target){
                  return mid-1;
              } 
              
              if(mid<end && arr[mid+1]==target){
                  return mid+1;
              }
              
              if(arr[mid]<target){
                  start=mid+1;
              }else{
                  end=mid-1;
              }
              
              mid=start+(end-start)/2;
          }
          
          return -1;
          
      }
  };