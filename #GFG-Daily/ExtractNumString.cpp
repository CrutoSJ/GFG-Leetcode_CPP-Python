// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1

// Date-> 22/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long ExtractNumber(string sentence) {
        long long count=0,n=0;
        bool indicate=false;
        for(char x:sentence)
        {
            if(x>='0' && x<='9')
            {
                n=n*10+(x-'0');
                if(x=='9')
                indicate=true;
            }
            else if(x==' ')
            {
                if(!indicate)
                count=max(count,n);
                indicate=false;
                n=0;
            }
        }
        if(indicate==false)
        count=max(count,n);
        return count==0?-1:count;
    }
};