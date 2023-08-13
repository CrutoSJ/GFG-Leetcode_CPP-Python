// #Question:-

// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.size(); i++){
            s[i] = tolower(s[i]);
        }
        return s;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    cin.ignore();

    Solution solution;
    while(t--){
        string input;
        cout << "Enter a string: ";
        getline(cin, input);
        
        string result = solution.toLowerCase(input);
        cout << "Lowercase: " << result << endl;
    }

    return 0;
}