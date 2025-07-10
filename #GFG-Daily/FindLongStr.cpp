// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1

// Date-> 10/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestString(vector<string> &words){
        sort(words.begin(), words.end());
        unordered_map<string, int>ump;
        for(auto &i : words)    ump[i]++;
        string s;   int l = 0;
        for(auto &i : words){
            string x;    int n = i.size();
            for(int j = 0; j < n; j++){
                x += i[j];
                if(!ump[x]){
                    n = 0;  break;
                }
            }
            if(n > l){
                s = i;  l = n;
            }
        }
        return s;
    }
};