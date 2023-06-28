// Question:-

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>s1,t1;
        for(int i=0;i<s.size();i++){
            s1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            t1[t[i]]++;
        }
        if(s.size() != t.size()) return false;
        if(s1 == t1) return true;
        return false;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        string s, t;
        cout << "Enter string s: ";
        cin >> s;
        cout << "Enter string t: ";
        cin >> t;
        Solution obj;
        if(obj.isAnagram(s, t)){
            cout << "t is an anagram of s." << endl;
        }
        else{
            cout << "t is not an anagram of s." << endl;
        }
    }
    return 0;

}