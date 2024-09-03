// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

// Date-> 03/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    	int LCS(string str1, string str2) {
            int n = str1.size();
            int m = str2.size();
            
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[n][m];
        }

	public:
    	int minOperations(string str1, string str2) 
    	{ 
    	    int lenLCS = LCS(str1, str2);
            int deletions = str1.length() - lenLCS;
            int insertions = str2.length() - lenLCS;
            return deletions + insertions;
    	    
    	} 
};