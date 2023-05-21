// Question:-

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
// #Open brackets must be closed by the same type of brackets.
// #Open brackets must be closed in the correct order.
// #Every close bracket has a corresponding open bracket of the same type.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isValid(string s){
        stack<char> cnt;
        for( char c : s){
            if ( c == '(' || c == '{' || c == '['){
                cnt.push(c);
            } else {
                if (cnt.empty()){
                    return false;
                }

                else if ( c == '}' && cnt.top() == '{'){
                    cnt.pop();
                } else if ( c == ']' && cnt.top() == '['){
                    cnt.pop();
                } else if ( c == ')' && cnt.top() == '('){
                    cnt.pop();
                } else{
                    return false;
                }
            }
        }
        return cnt.empty();
    }

};

int main() {
    int t;
    cout << "Enter the no. of test cases: " << endl;
    cin >> t;

    while(t--){
        string s;
        cout << "Enter the Parentheses: ";
        cin >> s;

        Solution a;
        auto ans = a.isValid(s);
        cout << ans << endl;
    }

}