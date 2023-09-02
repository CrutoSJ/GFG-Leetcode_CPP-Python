//  Question:-

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(int n){
        int x=0;
        while(n>0){
            int c=n%10;
            x=x+c*c;
            n=n/10;
        }
        return x;
    }
    bool isHappy(int n) {
        unordered_set<int> bhag;
        while(n!=1 && !bhag.count(n)){
            bhag.insert(n);
            n=solve(n);
            cout<<n<<" ";
        }
        if(n==1)return true;
        return false;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int num;
        cout << "Enter a number: ";
        cin >> num;

        Solution obj;
        bool isHappyNumber = obj.isHappy(num);

        if (isHappyNumber)
            cout << num << " is a happy number." << endl;
        else
            cout << num << " is not a happy number." << endl;
    }

}