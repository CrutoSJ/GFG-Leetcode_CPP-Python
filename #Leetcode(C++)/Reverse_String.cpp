// #Question:-

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
        
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the length of the string: ";
        cin >> n;

        vector<char> inputString(n);
        cout << "Enter the string characters: ";
        for (int i = 0; i < n; ++i) {
            cin >> inputString[i];
        }

        Solution solution;
        solution.reverseString(inputString);

        cout << "Reversed string: ";
        for (char c : inputString) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}