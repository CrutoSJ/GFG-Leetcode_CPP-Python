// #Question:-

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool checkPalindrome(string& str, int start, int end){
        while(start<=end){
            if(str[start++]!=str[end--]){
                return false;
            }
        }
        return true;
    }
    
    
    void helper(int idx, string& s, vector<string>& ds, vector<vector<string>>& ans){
        
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i=idx;i<s.size();i++){
            
            if(checkPalindrome(s,idx,i)==true){
                ds.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,ds,ans);
                ds.pop_back();          
            }
            
        }
    }
    
    
    
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> ds;
        helper(0,s,ds,ans);
        return ans;
        
        
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >>t;
    while(t--){
        string s;
        cout << "Enter the string: ";
        cin >> s;

        Solution sol;
        vector<vector<string>> result = sol.partition(s);

        cout << "Palindromic partitions:" << endl;
        for (const vector<string>& partition : result) {
            for (const string& palindrome : partition) {
                cout << palindrome << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
