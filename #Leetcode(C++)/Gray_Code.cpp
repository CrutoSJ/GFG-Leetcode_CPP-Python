// Question:-

// An n-bit gray code sequence is a sequence of 2n integers where:

// Every integer is in the inclusive range [0, 2n - 1],
// The first integer is 0,
// An integer appears no more than once in the sequence,
// The binary representation of every pair of adjacent integers differs by exactly one bit, and
// The binary representation of the first and last integers differs by exactly one bit.
// Given an integer n, return any valid n-bit gray code sequence.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for(int i = 1; i <= n; i++) {
            vector<int> rev = res;
            reverse(begin(rev), end(rev));
            int val = pow(2,i-1);
            for(int v : rev) res.push_back(v+val);
        }
        return res;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    Solution obj;
    while(t--){
        int n;
        cout << "Enter the value of n: ";
        cin >> n;
        vector<int> result = obj.grayCode(n);

        cout << "Gray code sequence for n = " << n << " is: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;

}