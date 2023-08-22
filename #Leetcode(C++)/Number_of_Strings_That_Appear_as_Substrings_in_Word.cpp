// #Question:-
// Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

// A substring is a contiguous sequence of characters within a string.

// Solution:-


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numOfStrings(vector<string>& patt, string word) {
        int count = 0;
        for(auto i : patt) {
            if(word.find(i) != -1) count++;
        }
        return count;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter number of patterns: ";
        cin >> n;

        vector<string> patterns(n);
        cout << "Enter patterns:" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> patterns[i];
        }

        string word;
        cout << "Enter the word: ";
        cin >> word;

        Solution sol;
        int result = sol.numOfStrings(patterns, word);
        cout << "Number of strings in patterns that exist as a substring in word: " << result << endl;
    }

    return 0;
}