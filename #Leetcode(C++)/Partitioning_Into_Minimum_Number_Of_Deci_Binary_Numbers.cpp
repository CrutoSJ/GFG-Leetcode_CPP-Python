// #Question:-

// A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

// Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for (char digit : n) {
            int currentDigit = digit - '0';  // Convert character to integer
            maxDigit = max(maxDigit, currentDigit);
        }
        return maxDigit;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    Solution solution;

    while (t--) {
        string n;
        cout << "Enter the positive decimal integer: ";
        cin >> n;
        
        int result = solution.minPartitions(n);
        cout << "Minimum number of positive deci-binary numbers needed for " << n << " is: " << result << "\n";
    }

    return 0;

}

