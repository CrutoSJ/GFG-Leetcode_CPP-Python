// Question:-

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result;

        if (!digits.empty()) {
            letterComb(digits, phoneMap, "", 0, result);
        }

        return result;
    }

    void letterComb(const string& digits, const unordered_map<char, string>& phoneMap, string current, int index, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = phoneMap.at(digits[index]);

        for (char letter : letters) {
            letterComb(digits, phoneMap, current + letter, index + 1, result);
        }
    }
};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        Solution solution;
        string input;

        cout << "Enter digits: ";
        cin >> input;

        vector<string> combinations = solution.letterCombinations(input);

        cout << "Letter combinations:" << endl;
        for (const string& combination : combinations) {
            cout << combination << " ";
        }
        cout << endl;
    }

    return 0;
}
