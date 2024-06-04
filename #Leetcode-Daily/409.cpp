// #Question:-

// Link-> https://leetcode.com/problems/longest-palindrome/

// Date-> 04/06/24

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int oddFre = 0;
        unordered_map<char,int>count;
        
        for(char c : s){
            count[c]++;
            
            if(count[c]%2==1){
                oddFre++;
            } else{
                oddFre--;
            }
        }
        
        if(oddFre>0){
            return s.length() - oddFre + 1 ;
        } else{
            return s.length();
        }
    }
};