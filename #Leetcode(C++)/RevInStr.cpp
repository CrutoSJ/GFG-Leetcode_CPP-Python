// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/reverse-words-in-a-string_696444

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

string reverseString(string &str){
    // Write your code here.
    int n=str.length();
    string ans;
    for(int i = n-1;i>-1;i--) {
        if(isspace(str[i])) continue;
        if(isspace(str[i-1])||i==0) {
            for(int j=i;!(isspace(str[j]))&&j<n;j++) {
                ans.push_back(str[j]);
            }
            ans.push_back(' ');
        }
    }
    return ans;
}