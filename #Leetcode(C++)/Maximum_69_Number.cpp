// Question:-

// You are given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for(int i=0;i<str.length();i++){
            if(str[i]=='6'){
                str[i]='9';
                return stoi(str);
            }
        }
        return num;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int num;
        cout << "Enter a positive integer consisting only of digits 6 and 9: ";
        cin >> num;
        Solution obj;
        int result = obj.maximum69Number(num);
        cout << "Maximum number with at most one digit change: " << result << endl;
    }
    return 0;
}