// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

// Date-> 05/08/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalinSent(string &s) {
        string check;
        for (char ch : s)
        {
            if (isalnum(ch)) check += tolower(ch);
        }
        
        int l = 0, r = check.size() - 1;
        while (l < r)
        {
            if (check[l++] != check[r--]) return false;
        }

        return true;
        
    }
};