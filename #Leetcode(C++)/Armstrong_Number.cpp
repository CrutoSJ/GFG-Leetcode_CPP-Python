// Question:-

// For a given 3 digit number, find whether it is armstrong number or not. An Armstrong number of three digits is an integer such that the sum of the 
// cubes of its digits is equal to the number itself. Return "Yes" if it is a armstrong number else return "No".
// NOTE: 371 is an Armstrong number since 33 + 73 + 13 = 371

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string armstrongNumber(int n){
        int dup = n;
        int sum = 0;
        while ( n > 0){
                int ld = n % 10;
                sum = sum + (ld*ld*ld);
                n = n / 10;
        }
        if ( sum == dup){
            return "Yes";
        }
        else{ return "No";
        }
    }
};

int main(){
    int t;
    cin >> t;
    for( int i=0; i<t; i++){
        int n;
        cout << "Enter the integer: ";
        cin >> n;

        Solution solution;
        auto ArmSNum = solution.armstrongNumber(n);
        cout << ArmSNum << endl;
    }
    return 0;
}