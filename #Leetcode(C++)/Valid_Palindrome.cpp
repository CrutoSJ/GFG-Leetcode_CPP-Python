// Question:-

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }

};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    cin.ignore();

    Solution solution;
    while (t--) {
        string s;
        cout << "Enter the string: ";
        getline(cin, s);

        if (solution.isPalindrome(s)) {
            cout << "Palindrome" << endl;
        } else {
            cout << "Not a palindrome" << endl;
        }
    }

    return 0;
}