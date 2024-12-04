// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

// Date-> 04/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        string str = s2+'$'+s1+s1;
        int n = str.length(), i=0, j=1, m=s2.length();
        vector<int> lps(n,0);
        while(j<n){
            if(str[i] == str[j]){
                lps[j++]=++i;
                if(i==m)return true;
            } else if(i!=0){
                i=lps[i-1];
            } else{
                j++;
            }
        }
        return false;
    }
};