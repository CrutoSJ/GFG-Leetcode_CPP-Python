// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1

// Date-> 09/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left    = 2*i+1;
        int right   = 2*i+2;
        
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[i], arr[largest]);
            
            heapify(arr, n, largest);
        }
    }
  
    void heapSort(vector<int> &arr, int n){
        for(int i = n/2-1; i>=0; i--){
            heapify(arr, n, i);
        }
        
        for(int i=n-1; i>0; i--){
            swap(arr[0], arr[i]);
            
            heapify(arr, i, 0);
        }
    }
  public:
    int Maximize(vector<int> &arr) {
        int M = 1000000007;
        int n = arr.size();
        
        heapSort(arr, n);
        
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            ans = (ans + (long long)arr[i]*i) % M;
        }
        
        return ans;
    }
};