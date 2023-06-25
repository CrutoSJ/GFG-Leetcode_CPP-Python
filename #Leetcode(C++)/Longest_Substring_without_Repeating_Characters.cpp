// Question:-

// Given a string s, find the length of the longest substring without repeating characters.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        vector<int> charindex(128, -1);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charindex[s[right]] >= left) {
                left = charindex[s[right]] + 1;
            }
            charindex[s[right]] = right;
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        string str;
        cout << "Enter a string: ";
        cin >> str;
        
        Solution obj;
        int result = obj.lengthOfLongestSubstring(str);
        cout << "Length of the longest substring without repeating characters: " << result << endl;

    }

}