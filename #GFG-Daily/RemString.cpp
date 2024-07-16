// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/remaining-string3515/1

// Date-> 16/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution { 
private:
    int findPos(string s, char ch, int count){
        int cnt=0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ch) cnt++;
            if(cnt==count){
                return i;
            }
        }
        return -1;
    }

public:
    string printString(string s, char ch, int count) {
        string ans ="";
        int idx =  findPos(s,ch,count);
        
        if(idx == -1) return ans;
        
        for(int i=idx+1; i<s.length(); i++){
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};