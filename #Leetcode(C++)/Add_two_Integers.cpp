// Question:-

// Given two integers num1 and num2, return the sum of the two integers.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    short sum(int num1, int num2) {
        return (char)num1+(char)num2;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int num1, num2;
        cout << "Enter two integers: ";
        cin >> num1 >> num2;

        Solution obj;
        int result = obj.sum(num1, num2);
        cout << "Sum: " << result << endl;
    }

    return 0;

}