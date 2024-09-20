// #Question:-

// Link-> https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20

// Date-> 20/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(vector<int> &lps, string a){
        int i=0; 
        int j=1;

        while(j<a.length()){
            if(a[i]==a[j]){
                i++;
                lps[j]=i;
                j++;
            } else{
                if(i==0){
                    j++;
                } else{
                    i=lps[i-1];
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string a = s+"#"+t;

        vector<int> lps(a.length(), 0);

        func(lps, a);
        int i = lps[a.length()-1];

        string temp = s.substr(i);
        reverse(temp.begin(), temp.end());

        return temp+s;
    }
};