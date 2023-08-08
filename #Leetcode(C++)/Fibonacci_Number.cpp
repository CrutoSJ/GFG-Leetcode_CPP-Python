// #Question:-

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int fibonacci(int n){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        int prev1 = 0, prev2 = 1, curr;
        for(int i = 2; i <= n; i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    Solution sol;
    while(t--){
        int n;
        cout << "Enter the value of n: ";
        cin >> n;
        
        int result = sol.fibonacci(n);
        cout << "F(" << n << ") = " << result << endl;
    }
    return 0;
    
}