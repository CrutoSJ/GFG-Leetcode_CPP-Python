// Question:-

// Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

// Return an integer denoting the sum of all numbers in the given range satisfying the constraint.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i=1; i<=n; i++){
            if(i%3 == 0 || i%5 == 0 || i%7 == 0){
                sum = sum + i;
            }
        }
        return sum;
    }

};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the value n: ";
        cin >> n;

        Solution solution;
        auto ans = solution.sumOfMultiples(n);

        cout << "The sum is: " << ans;

        cout << endl;

    }
    return 0;

}