// Question:-

// Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle)
        {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        string columnTitle;
        cout << "Enter column title: ";
        cin >> columnTitle;
        
        Solution obj;
        int columnNumber = obj.titleToNumber(columnTitle);
        cout << "Column number: " << columnNumber << endl;
    }

    return 0;

}



