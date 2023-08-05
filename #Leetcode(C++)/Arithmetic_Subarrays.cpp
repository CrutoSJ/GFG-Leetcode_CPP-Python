// #Question:-

// A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

// For example, these are arithmetic sequences:

// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic:

// 1, 1, 2, 5, 7
// You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

// Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n=l.size();
        vector<bool>ans(n,true);
        vector<int>temp;
        temp=nums;

        for(int i=0;i<n;i++){
            int a=l[i];
            int b=r[i];
            sort(temp.begin()+a,temp.begin()+b+1);
            int q=temp[a+1]-temp[a];
            for(int j=a;j<b;j++){
                int bf =temp[j+1]-temp[j];
                if(bf!=q){
                    ans[i]=false;
                }
            }
            temp=nums;
        
        }
        return ans;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n, m;
        cout << "Enter the number of elements in nums array: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements of nums array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << "Enter the number of queries (m): ";
        cin >> m;
        vector<int> l(m), r(m);
        cout << "Enter the queries ranges (l and r): " << endl;
        for (int i = 0; i < m; i++) {
            cin >> l[i] >> r[i];
        }

        Solution sol;
        vector<bool> result = sol.checkArithmeticSubarrays(nums, l, r);

        cout << "Results: " << endl;
        for (bool res : result) {
            cout << (res ? "true" : "false") << " ";
        }
        cout << endl;
    }

    return 0;
}