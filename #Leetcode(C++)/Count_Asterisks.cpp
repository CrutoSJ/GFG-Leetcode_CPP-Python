// #Question:-

// You are given a string s, where every two consecutive vertical bars '|' are grouped into a pair. In other words, the 1st and 2nd '|' make a pair, the 3rd and 4th '|' make a pair, and so forth.

// Return the number of '*' in s, excluding the '*' between each pair of '|'.

// Note that each '|' will belong to exactly one pair.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countAsterisks(string s) {
        int ans = 0;
        bool between = false;
        for (char ch: s) {
            if (ch == '*' && !between) ans++;
            else if (ch == '|') between = !between;
        }
        return ans;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    cin.ignore();

    Solution solution;
    while(t--){
        while (t--) {
        string s;
        cout << "Enter the input string: ";
        getline(cin, s);

        int result = solution.countAsterisks(s);
        cout << "Number of '*' excluding those between pairs of '|' is: " << result << endl;
    }

    return 0;

    }
}