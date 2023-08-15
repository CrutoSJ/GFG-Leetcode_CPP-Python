// #Question:-

// You are given a string number representing a positive integer and a character digit.

// Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string removeDigit(string number, char digit) {
        string result = "";
        for(int i=0; i<number.size(); i++){
            if(number[i] == digit){
                string temp = number.substr(0,i)+number.substr(i+1,number.size());
                result = max(temp,result);
            }
            
            
        }
        return result;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        string number;
        char digit;

        cout << "Enter number: ";
        cin >> number;
        
        cout << "Enter digit to remove: ";
        cin >> digit;

        Solution solution;
        string result = solution.removeDigit(number, digit);

        cout << "Resulting string after removing " << digit << ": " << result << endl;
    }

    return 0;
}