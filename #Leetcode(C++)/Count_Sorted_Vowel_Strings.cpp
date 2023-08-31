// #Question:-

// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

// A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countVowelStrings(int n) {
        
        return (n+4)*(n+3)*(n+2)*(n+1) / 24;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    Solution solution;

    while(t--){
        int n;
        cout << "Enter the value of n: ";
        cin >> n;
        
        int result = solution.countVowelStrings(n);
        cout << "Number of lexicographically sorted vowel strings of length " << n << ": " << result << endl;
    }

    return 0;
}