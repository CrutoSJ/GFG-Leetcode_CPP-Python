// Question:-

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(),len2=nums2.size(),i=0,j=0;
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i<len1&&j<len2)
        {
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]==nums2[j]) 
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]) j++;
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
        
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n1, n2;
        cout << "Enter the size of nums1: ";
        cin >> n1;
        vector<int> nums1(n1);
        cout << "Enter elements of nums1: ";
        for (int i = 0; i < n1; i++)
            cin >> nums1[i];

        cout << "Enter the size of nums2: ";
        cin >> n2;
        vector<int> nums2(n2);
        cout << "Enter elements of nums2: ";
        for (int i = 0; i < n2; i++)
            cin >> nums2[i];

        Solution s;
        vector<int> result = s.intersection(nums1, nums2);

        cout << "Intersection: ";
        for (int num : result)
            cout << num << " ";
        cout << endl;
    }
    return 0;

}