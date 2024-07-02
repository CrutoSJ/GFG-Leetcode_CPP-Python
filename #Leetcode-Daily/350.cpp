// #Question:-

// Link-> https://leetcode.com/problems/intersection-of-two-arrays-ii/ 

// Date-> 02/07/24

// #Solution:-

#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        if(nums1.size() == 0 || nums2.size() == 0) return ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            int a = nums1[i];
            int b = nums2[j];
            if(a==b){
                ans.push_back(a);
                i++,j++;
            } else if(a>b){
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};