// #Question:-

// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).

// For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
// You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string truncateSentence(string s, int k) {
        int count=0;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                count++;
            }
            if(count==k)
            {
                break;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        int k;
        cout << "Enter sentence: ";
        getline(cin, s);
        cout << "Enter k: ";
        cin >> k;
        Solution solution;
        string result = solution.truncateSentence(s, k);
        cout << "Truncated sentence: " << result << endl;
    }
    return 0;
}