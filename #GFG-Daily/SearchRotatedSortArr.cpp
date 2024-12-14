// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

// Date-> 14/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int findPivot(vector<int>arr, int key, int n){
        int s=0;
        int e=n-1;
        int mid  = s + (e-s)/2;
        while(s<=e){
            if(s==mid){
                return mid;
            }
            if(arr[mid] >= arr[s]){
                s=mid;
            }
            else if(arr[mid]<arr[e]){
                e=mid;
            }
            mid  = s + (e-s)/2;
        }
        return mid;
    }
    
    int solve(vector<int>arr, int key, int start, int end){
        int s = start;
        int e = end;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] < key){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int pivot = findPivot(arr, key, n);
        
        if(key <= arr[pivot] && key >= arr[0]){
            return solve(arr,key, 0, pivot);
        }
        
        else{
            return solve(arr, key, pivot+1, n-1);
        }
    }
};