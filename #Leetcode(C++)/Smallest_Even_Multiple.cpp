// #Question 

// Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int smallestEvenMultiple(int n) {
        if(n%2==0){
            return n;
        }else{
            return 2*n;
        }
        
    }
};


int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    
    Solution method;

    while(t--){
        int n;
        cout << "Enter a positive integer: ";
        cin >> n;
        
        int result = method.smallestEvenMultiple(n); // Call the smallestEvenMultiple function
        
        cout << "The smallest positive integer that is a multiple of both 2 and " << n << " is: " << result << endl;
    }

    return 0;

}