// Question:-

// You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

// Given the string command, return the Goal Parser's interpretation of command.

// Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string s;
        int n = command.size();
        for (int i = 0; i < n; ++i) {
            if (command[i] == 'G') {
                s += 'G';
            }
            else if (command[i] == '(' && i + 1 < n) {
                if (command[i + 1] == ')') {
                    s += 'o';
                    ++i;
                }
                else if (command[i + 1] == 'a' && i + 3 < n && command[i + 2] == 'l' && command[i + 3] == ')') {
                    s += "al";
                    i += 3;
                }
            }
        }
        return s;
    }
};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    cin.ignore();

    while(t--){
        string input;
        cout << "Enter command: ";
        getline(cin, input);

        Solution solution;
        string result = solution.interpret(input);

        cout << "Interpreted command: " << result << endl;
    }

    return 0;
}
