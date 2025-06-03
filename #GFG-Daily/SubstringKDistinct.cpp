// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

// Date-> 03/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubstr(string& s, int k) {
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            vector<int> freq(26,0);
            int distinct = 0;
            
            for(int j=i; j<s.size(); j++){
                if(freq[s[j] - 'a'] == 0){
                    distinct++;
                }
                freq[s[j] - 'a']++;
                if(distinct == k){
                    cnt++;
                }
                if(distinct > k){
                    break;
                }
            }
        }
        return cnt;
    }
};
