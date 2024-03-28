// #Question:-

// #Link-> https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();
        
        if (n != m) return false;
        
        map<char, char> m1, m2;
        
        for (int i = 0; i < n; i++)
        {
            if (m1.find(str1[i]) == m1.end() && m2.find(str2[i]) == m2.end())
            {
                m1[str1[i]] = str2[i];
                m2[str2[i]] = str1[i];
            }
            else if (m1[str1[i]] != str2[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
};