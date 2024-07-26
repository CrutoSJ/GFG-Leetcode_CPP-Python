// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/k-pangrams0909/1

// Date-> 26/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool kPangram(string str, int k) {
        vector<int>cnt(26,0);
        int op = 0, count = 0;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == ' '){
                continue;
            } else{
                count++;
                cnt[str[i]-'a']++;
            }
        }
        
        if(count<26){
            return false;
        }
        
        for(int i=0; i<26; i++){
            if(cnt[i]==0){
                op++;
            } else{
                count++;
            }
        }
        return op<=k;
    }
};