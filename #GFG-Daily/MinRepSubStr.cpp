// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1

// Date-> 08/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        int cnt = 1;
        string temp = s1;
        
        while(s1.size() < s2.size()){
            s1+=temp;
            cnt++;
        }
        if(s1.find(s2)!=-1){
            return cnt;
        }
        s1+=temp;
        cnt++;
        if(s1.find(s2)!=-1){
            return cnt;
        }
        return -1;
    }
};