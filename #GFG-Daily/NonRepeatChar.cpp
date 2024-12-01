// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

// Date-> 01/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        char ans;
        unordered_map<char,int> freq;
        
        for(char &ch : s){
            freq[ch]++;
        }
        
        for(char &ch : s){
            if(freq[ch] == 1){
                return ch;
            }
        }
        return '$';
    }
};