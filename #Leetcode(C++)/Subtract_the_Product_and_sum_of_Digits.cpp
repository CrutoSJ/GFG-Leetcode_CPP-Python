// Question:-

// Given an integer number n, return the difference between the product of its digits and the sum of its digits.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int subtractProductAndSum(int n) {
    int pro=1;
    int sum=0;
    
    while(n>0){
        int rem=n%10;
        sum += rem;
        pro *= rem;
        n /= 10;
    }
    return pro-sum;
    }

};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the integer number: ";
        cin >> n;
        
        Solution obj;
        int result = obj.subtractProductAndSum(n);
        
        cout << "Difference between product and sum of digits: " << result << endl;
    }
    
    return 0;

}