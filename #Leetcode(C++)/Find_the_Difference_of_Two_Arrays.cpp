// #Question

// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> distinct_nums1, distinct_nums2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        return {distinct_nums1, distinct_nums2};
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    Solution solution;

    while(t--){
        int n, m;
        cout << "Enter size of nums1 and nums2: ";
        cin >> n >> m;

        vector<int> nums1(n), nums2(m);
        cout << "Enter elements of nums1: ";
        for (int i = 0; i < n; ++i) {
            cin >> nums1[i];
        }

        cout << "Enter elements of nums2: ";
        for (int i = 0; i < m; ++i) {
            cin >> nums2[i];
        }

        vector<vector<int>> result = solution.findDifference(nums1, nums2);
        cout << "Distinct integers in nums1 not in nums2: ";
        for (int num : result[0]) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Distinct integers in nums2 not in nums1: ";
        for (int num : result[1]) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}