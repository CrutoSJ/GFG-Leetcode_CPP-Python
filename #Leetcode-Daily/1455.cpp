// #Question:-

// Link-> https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

// Date-> 02/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cnt = 1;
        string temp = "";
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i] == ' '){
                cnt++;
                temp = "";
                continue;
            } 
            temp += sentence[i];
            if(temp == searchWord){
                return cnt;
            }
        }
        return temp == searchWord ? cnt : -1;
    }
};