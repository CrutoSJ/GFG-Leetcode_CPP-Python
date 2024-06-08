// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1

// Date-> 08/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int s=0;
        int e=n;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr1[mid] != arr2[mid]){
                ans = mid;
                e=mid-1;
            } else {
                s = mid+1;
            }
        }
        return ans;
    }
};