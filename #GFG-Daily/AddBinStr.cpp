// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/add-binary-strings3805/1

// Date-> 29/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size()-1;
        int j = s2.size()-1;
        string res = "";
        int carry = 0;
        
        while(i>=0 || j>=0){
            int cnt = 0;
            if(i>=0 && s1[i] == '1')cnt++;
            if(j>=0 && s2[j] == '1')cnt++;
            
            if(cnt+carry == 0){
                res += '0';
                carry = 0;
            } else if(cnt + carry == 1){
                res += '1';
                carry = 0;
            } else if(cnt + carry == 2){
                res += '0';
                carry = 1;
            } else if(cnt + carry == 3){
                res += '1';
                carry = 1;
            }
            i--, j--;
        }
        
        if(carry == 1){
            res += to_string(carry);
        }
        
        reverse(res.begin(), res.end());
        i=0;
        while(res[i] == '0'){
            i++;
        }
        return res.substr(i);
    }
};