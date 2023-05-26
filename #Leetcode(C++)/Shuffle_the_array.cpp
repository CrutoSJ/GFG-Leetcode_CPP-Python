// Question:-

// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
// Return the array in the form [x1,y1,x2,y2,...,xn,yn].

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> shuffle(vector<int>& nums, int n){

        vector<int> ans(2*n);
        for(int i=0; i < 2*n; i++){
            if( i % 2 == 0){
                ans[i] = nums[i/2];
            }
            else{
                ans[i] = nums[n + i / 2];
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t--){
        int n;
        cout << "Enter the value of n: ";
        cin >> n;

        vector<int> nums(2*n);
        cout << "Enter array elements: ";
        for (int i=0; i<2*n; i++){
            cin >> nums[i];
        }

        Solution solution;
        auto ans = solution.shuffle(nums,n);
        
        cout << "Shuffled array: ";
        for(int i=0; i < 2*n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}