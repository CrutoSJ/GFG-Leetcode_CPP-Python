// #Questions:-

// There is a programming language with only four operations and one variable X:

// ++X and X++ increments the value of the variable X by 1.
// --X and X-- decrements the value of the variable X by 1.
// Initially, the value of X is 0.

// Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int finalValueAfterOperations(vector<string>& operations){
        int a=0;
        for(int i=0; i<operations.size(); i++){
            if(operations[i] == "++X" || operations[i] == "X++"){
                a = a + 1;
            }
            else if (operations[i] == "--X" || operations[i] == "X--"){
                a = a - 1 ;
            }
        }
        return a;
    }

};

int main(){
    int t;
    cout << "Enter the value of test cases: ";
    cin >> t;
    while (t--){
        int n;
        cout << "Enter the no. of elements: ";
        cin >> n;

        vector<string> operations(n);

        cout << "Enter the elements: ";

        for(int i=0; i<n; i++){
            cin >> operations[i];
        }

        Solution solution;
        auto z = solution.finalValueAfterOperations(operations);
        cout << z <<endl;

    }
    return 0;
}