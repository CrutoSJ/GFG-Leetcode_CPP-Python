// #Question:-

// A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

// You are given an array of strings sentences, where each sentences[i] represents a single sentence.

//Return the maximum number of words that appear in a single sentence.

// Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int len = sentences.size();
        int max_length = 0, length = 0;
        int i = 0, j = 0;
        while (i < len) {
            if (sentences[i][j] == ' ') {
                length++;
                j++;
            }
            else if (sentences[i][j] == '\0') {
                i++;
                j = 0;
                max_length = max(max_length, length + 1);
                length = 0;
            }
            else
                j++;
        }
        return max_length;
    }
};

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    
    Solution solution;
    
    while (t--) {
        int n;
        cout << "Enter the number of sentences: ";
        cin >> n;
        
        vector<string> sentences(n);
        cout << "Enter the sentences:\n";
        for (int i = 0; i < n; i++) {
            cin.ignore();
            getline(cin, sentences[i]);
        }
        
        int result = solution.mostWordsFound(sentences);
        cout << "Maximum length of words found: " << result << endl;
    }
    
    return 0;
}
