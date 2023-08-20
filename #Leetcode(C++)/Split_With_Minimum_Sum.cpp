// #Question

// Given a positive integer num, split it into two non-negative integers num1 and num2 such that:

// The concatenation of num1 and num2 is a permutation of num.
// In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
// num1 and num2 can contain leading zeros.
// Return the minimum possible sum of num1 and num2.

// Notes:

// It is guaranteed that num does not contain any leading zeros.
// The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int splitNum(int num) {
        int num1 = 0, num2 = 0, x = 1;
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num /= 10;
        }
        sort(v.begin(),v.end());
        num = 0;
        for(auto &i: v){
            num *= 10;
            num += i;
        }
        while(num){
            num1 += x*(num%10);
            num /= 10;
            num2 += x*(num%10);
            num /= 10;
            x *= 10;
        }
        return num1+num2;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int num;
        cout << "Enter the positive integer: ";
        cin >> num;

        Solution sol;
        int result = sol.splitNum(num);
        cout << "Minimum possible sum of num1 and num2: " << result << endl;
    }
    return 0;
}