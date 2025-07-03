// #Question:-

// Link-> https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/?envType=daily-question&envId=2025-07-03

// Date-> 03/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string getNewStr(string &str){
        string temp = "";
        for(char &ch : str){
            char newChar = ch + 1;
            if (newChar > 'z') {
                newChar = 'a';
            }
            temp += newChar;
        }
        return temp;
    }
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size()<k){
            string temp = getNewStr(word);
            word += temp;
        }
        return word[k-1];
    }
};