// Question:-

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
string frequencySort(string s) {
    string ans = "";
    unordered_map<char, int> charFreq;

    for (int i = 0; i < s.size(); i++) {
        charFreq[s[i]]++;
    }

    vector<pair<int, char>> freq;
    for (auto it : charFreq) {
        freq.push_back(make_pair(it.second, it.first));
    }

    sort(freq.begin(), freq.end(), greater<pair<int, char>>());

    for (auto it : freq) {
        for (int i = 0; i < it.first; i++) {
            ans += it.second;
        }
    }

    return ans;
}
};    

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){

        string input;
        cout << "Enter a string: ";
        cin >> input;

        Solution solution;
        string result = solution.frequencySort(input);

        cout << "Sorted string: " << result << endl;
    }

    return 0;
}

