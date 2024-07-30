// #Question:-

// Link-> https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30

// Date-> 30/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int count_a = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a'){
                count_a++;
            }
        }

        int ans = INT_MAX;
        int count_b=0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a'){
                count_a--;
            }
            
            ans = min(ans, count_a + count_b);

            if(s[i] == 'b'){
                count_b++;
            }
        }
        return ans;
    }
};