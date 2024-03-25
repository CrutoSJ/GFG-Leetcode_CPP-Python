// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void solve(vector<string>& ans, int zeros, int ones, int n, string temp, int i){
        if(i==n){
            ans.push_back(temp);
            return ;
        }
        
        solve(ans,zeros, ones+1,n, temp+'1',i+1);
        
        if(zeros+1<=ones){
            solve(ans,zeros+1,ones, n, temp+'0',i+1);
            return;
        }
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string>ans;
	    string s ="";
	    solve(ans,0,0,n,s,0);
	    return ans;
	}
};