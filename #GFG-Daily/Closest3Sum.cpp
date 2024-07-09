// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/three-sum-closest/1

// Date-> 09/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> arr, int target) {
        if(arr.size()<3){
            return -1;
        }
        sort(arr.begin(), arr.end());
        int ans = INT_MAX, diff = INT_MAX;
        for(int i=0; i<arr.size(); i++){
            int s=i+1, e=arr.size()-1;
            while(s<e){
                int sum = arr[i] + arr[s] + arr[e];
                if(sum == target){
                    return sum;
                } else if(sum<target){
                    s++;
                } else{
                    e--;
                }
                if(abs(target-sum) < diff){
                    diff = abs(target-sum);
                    ans = sum;
                } else if(abs(target-sum) == diff){
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};