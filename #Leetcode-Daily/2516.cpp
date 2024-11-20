// #Question:-

// Link-> https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/?envType=daily-question&envId=2024-11-20

// Date-> 20/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int cnt_a = 0, cnt_b = 0, cnt_c = 0;

        for(char &ch : s){
            if(ch == 'a')cnt_a++;
            else if(ch == 'b')cnt_b++;
            else cnt_c++;
        }

        if(cnt_a < k || cnt_b < k || cnt_c < k){
            return -1;
        }

        int i=0, j=0;
        int maxDel = 0;

        while(j<n){
            if(s[j] == 'a')cnt_a--;
            else if(s[j] == 'b')cnt_b--;
            else cnt_c--;

            while(i<=j && (cnt_a < k) || (cnt_b < k) || (cnt_c < k)){
                if(s[i] == 'a')cnt_a++;
                else if(s[i] == 'b')cnt_b++;
                else cnt_c++;
                i++;
            }
            maxDel = max(maxDel, j-i+1);
            j++;
        }
        return n-maxDel;
    }
};