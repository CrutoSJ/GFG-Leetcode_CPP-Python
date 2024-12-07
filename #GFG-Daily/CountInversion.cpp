// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// Date-> 07/12/24

// #Solution:

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
     long long int merge_helper(vector<int> &arr, int low, int high, int mid) {
        long long int count = 0;
        int left_size = mid - low + 1;
        int right_size = high - mid;
    
        vector<long long int> left(left_size);
        vector<long long int> right(right_size);
    
        for (int i = 0; i < left_size; i++) {
            left[i] = arr[low + i];
        }
        for (int i = 0; i < right_size; i++) {
            right[i] = arr[mid + 1 + i];
        }
    
        int i = 0;
        int j = 0;
        int k = low;
    
        while (i < left_size && j < right_size) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
                count += (left_size - i);
            }
            k++;
        }
    
        while (i < left_size) {
            arr[k] = left[i];
            i++;
            k++;
        }
    
        while (j < right_size) {
            arr[k] = right[j];
            j++;
            k++;
        }
    
        return count;
    }
  
    long long int merge_sort_helper(vector<int> &arr, int low, int high) {
        long long int count = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            count += merge_sort_helper(arr, low, mid);
            count += merge_sort_helper(arr, mid + 1, high);
            count += merge_helper(arr, low, high, mid);
        }
        return count;
    }    
    
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int N = arr.size();
        return merge_sort_helper(arr, 0, N-1);
    }
};