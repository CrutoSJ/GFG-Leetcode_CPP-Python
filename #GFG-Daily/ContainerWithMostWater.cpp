// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

// Date-> 13/01/25 && 31/08/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxWater(vector<int> &arr) {
        int i=0, j=arr.size()-1, res=0;
        while(i<j){
            res = max(res, (j-i) * min(arr[i],arr[j]));
            arr[i]<arr[j] ? i++ : j--;
        }
        return res;
    }
};
