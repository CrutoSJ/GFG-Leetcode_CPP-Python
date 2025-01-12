// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

// Date-> 12/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxWater(vector<int> &arr) {
        if (arr.empty()) return 0;

        int left = 0, right = arr.size() - 1;
        int left_max = 0, right_max = 0;
        int water_trapped = 0;
    
        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= left_max) {
                    left_max = arr[left]; 
                } else {
                    water_trapped += left_max - arr[left];  
                }
                left++;
            } else {
                if (arr[right] >= right_max) {
                    right_max = arr[right]; 
                } else {
                    water_trapped += right_max - arr[right];  
                }
                right--;
            }
        }
    
        return water_trapped;
    }
};