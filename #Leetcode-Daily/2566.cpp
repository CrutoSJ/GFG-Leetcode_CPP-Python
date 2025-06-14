// #Question:-

// Link-> https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/?envType=daily-question&envId=2025-06-14

// Date-> 14/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        int maxi=0;
        int mini=0;
        char ch='&';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='9' && ch=='&')
            {
                ch=s[i];
                s[i]='9';
            }
            else if(s[i]==ch)
            {
                s[i]='9';
            }

        }
        maxi=stoi(s);
        string s1=to_string(num);
        char c='&';
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!='0' && c=='&')
            {
                c=s1[i];
                s1[i]='0';
            }
            else if(s1[i]==c)
            {
                s1[i]='0';
            }
        }
        mini=stoi(s1);
        return maxi-mini;
    }
};