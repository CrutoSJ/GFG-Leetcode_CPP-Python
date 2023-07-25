// #Question:-

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]= 0 + dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    Solution sol;
    while(t--){
        string word1, word2;
        cout << "Enter word1: ";
        cin >> word1;
        cout << "Enter word2: ";
        cin >> word2;

        int result = sol.minDistance(word1, word2);
        cout << "Minimum number of operations required: " << result << endl;
    }

    return 0;

}