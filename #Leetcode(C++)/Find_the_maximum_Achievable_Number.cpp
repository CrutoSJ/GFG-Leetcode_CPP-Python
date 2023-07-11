// Question:-

// You are given two integers, num and t.

// An integer x is called achievable if it can become equal to num after applying the following operation no more than t times:

// Increase or decrease x by 1, and simultaneously increase or decrease num by 1.
// Return the maximum possible achievable number. It can be proven that there exists at least one achievable number.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int theMaximumAchievableX(int num, int t) {
        return 2*t+num;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int num, t;
        cout << "Enter num and t: ";
        cin >> num >> t;
        
        Solution obj;
        int maxAchievable = obj.theMaximumAchievableX(num, t);
        cout << "Maximum Achievable Number: " << maxAchievable << endl;
    }

    return 0;
}