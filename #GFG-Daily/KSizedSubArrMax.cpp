// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// Date -> 27/09/24 && 02/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        vector<int> result;
        deque<int> dq;
        
        for(int i=0; i<arr.size(); i++){
            if(dq.size() && (dq.front() == i-k)){
                dq.pop_front();
            }
            while(dq.size() && (arr[dq.back()]<=arr[i])){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                result.push_back(arr[dq.front()]);
            }
        }
        return result;
    }
};