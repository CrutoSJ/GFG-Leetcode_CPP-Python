// Question:-

// Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

// Given a balanced string s, split it into some number of substrings such that:

// Each substring is balanced.
// Return the maximum number of balanced strings you can obtain.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int balancedStringSplit(string s) {
        int count = 0; int m = 0; 

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'R') count++; else count--; 
            if(count == 0) m++; 
        
    }

    return m;  

    }

};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        string s;
        cout << "Enter the balanced string: ";
        cin >> s;
        
        Solution obj;
        int result = obj.balancedStringSplit(s);
        
        cout << "Maximum number of balanced strings: " << result << endl;
    }
    return 0;


}