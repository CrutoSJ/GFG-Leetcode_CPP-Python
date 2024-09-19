// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

// Date-> 19/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        vector<string> words;
        string word = "";
        for(int i=0; i<str.length(); i++){
            if(str[i] == '.'){
                words.push_back(word);
                word = "";
            } else{
                word += str[i];
            }
        }
        words.push_back(word);
        
        reverse(words.begin(), words.end());
        
        string result = "";
        
        for(int i=0; i<words.size(); i++){
            result += words[i];
            if(i != words.size()-1){
                result += '.';
            }
        }
        
        return result;
    }
};