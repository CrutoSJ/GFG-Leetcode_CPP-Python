// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

// Date-> 06/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isValid(string str) {
        int n = str.length();
        int dotCount = 0;
        int num = 0;
        int cnt = 0;  
        
        for(int i = 0; i <= n; i++) {
            if (i < n && str[i] != '.') {
                if (str[i] < '0' || str[i] > '9') return 0;  
                if (cnt == 0 && str[i] == '0' && i + 1 < n && str[i + 1] != '.') return 0; 
                num = num * 10 + (str[i] - '0');
                if (num > 255) return 0; 
                cnt++;
            } else {
                if (cnt == 0) return 0;
                cnt = 0;
                num = 0;
                dotCount++;
            }
        }
        return dotCount == 4 ? 1 : 0;
    }
};