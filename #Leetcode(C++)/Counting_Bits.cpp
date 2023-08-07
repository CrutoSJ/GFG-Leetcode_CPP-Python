// #Question:-

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++){
            int sum = 0,num=i;
            while(num != 0){
                sum += num%2;
                num /=2;
            }
            ans.push_back(sum);
        }
        return ans;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the value of n: ";
        cin >> n;

        Solution solution;
        vector<int> result = solution.countBits(n);

        cout << "Resulting array: ";
        for (int i = 0; i <= n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}