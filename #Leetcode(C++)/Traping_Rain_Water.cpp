// #Question:-

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// #Soution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2)
            return 0;

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int trapWater = 0;

        for (int i = 1; i < n - 1; ++i) {
            int minHeight = min(leftMax[i], rightMax[i]);
            if (minHeight > height[i]) {
                trapWater += minHeight - height[i];
            }
        }

        return trapWater;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    while(t--){
        int n;
        cout << "Enter the number of elements in the elevation map: ";
        cin >> n;

        vector<int> height(n);
        cout << "Enter the heights of the elevation map: ";
        for (int i = 0; i < n; ++i) {
            cin >> height[i];
        }

        Solution sol;
        int trappedWater = sol.trap(height);
        cout << "Trapped water: " << trappedWater << "\n";
    }

    return 0;

}