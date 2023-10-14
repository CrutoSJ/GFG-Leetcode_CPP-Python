// #Question:-

// You are given positive integers n and m.

// Define two integers, num1 and num2, as follows:

// num1: The sum of all integers in the range [1, n] that are not divisible by m.
// num2: The sum of all integers in the range [1, n] that are divisible by m.
// Return the integer num1 - num2.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int differenceOfSums(int n, int m) {
        int sum1 = 0,sum2 = 0;
        for(int i= 1; i<=n; i++) if(i%m!=0) sum1 += i;
        for(int i= 1; i<=n; i++) if(i%m==0) sum2 += i;
        return sum1-sum2;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        while (t--) {
        int n, m;
        cout << "Enter n and m for the current test case: ";
        cin >> n >> m;

        Solution obj;
        int result = obj.differenceOfSums(n, m);
        cout << "Difference of sums for the test case: " << result << endl;
    }

    return 0;

    }
}