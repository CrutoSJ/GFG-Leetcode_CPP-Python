// Question:-

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(string op, int open, int close, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        if(open == close){
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }
        else if(open == 0){
            string op1 = op;
            op1.push_back(')');
            solve(op1, open, close-1, ans);
        }
        else if(close == 0){
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }
        else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, open-1, close, ans);
            solve(op2, open, close-1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op = "";
        solve(op, open, close, ans);
        return ans;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of pairs of parentheses: ";
        cin >> n;
        Solution sol;
        vector<string> result = sol.generateParenthesis(n);
        cout << "Combinations of well-formed parentheses: ";
        for (string s : result) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;

}