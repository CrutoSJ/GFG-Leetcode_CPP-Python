// Question:-

// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

// Return the number of consistent strings in the array words.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>ans(allowed.begin(),allowed.end());
        int count=0;
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            bool isthere=true;
            for(int j=0;j<temp.length();j++){
                if(ans.find(temp[j])==ans.end()){
                    isthere=false;
                    break;
                }
            }
            if(isthere)count++;
        }
        return count;
        
    }
};

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    
    while (t--) {
        string allowed;
        cout << "Enter the allowed characters: ";
        cin >> allowed;

        int n;
        cout << "Enter the number of words: ";
        cin >> n;

        vector<string> words(n);
        cout << "Enter the words: ";
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

        Solution solution;
        int result = solution.countConsistentStrings(allowed, words);
        cout << "Number of consistent strings: " << result << endl;
    }

    return 0;
}