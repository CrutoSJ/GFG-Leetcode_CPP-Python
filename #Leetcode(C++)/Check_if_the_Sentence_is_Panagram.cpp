// #Question:-

// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool checkIfPangram(string sentence) {
        for(char c='a';c<='z';c++){
            if(sentence.find(c)==string::npos)
                return false;
        }
        return true;
    }
};

int main() {
    int t;
    cout << "Enter no.of test cases: ";
    cin >> t;
    cin.ignore();

    Solution solution;
    while (t--) {
        string sentence;
        cout << "Enter the sentence: ";
        getline(cin, sentence);

        bool isPangram = solution.checkIfPangram(sentence);
        if (isPangram) {
            cout << "The sentence is a pangram." << endl;
        } else {
            cout << "The sentence is not a pangram." << endl;
        }
    }

    return 0;
}