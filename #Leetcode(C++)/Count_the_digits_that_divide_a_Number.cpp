// Question:-

// Given an integer num, return the number of digits in num that divide num.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countDigits(int num) {
        int count,a,n = num;
        while(num>0)
        {
            a = num%10;
            if(n%a == 0)
            {
                count++;
            }
            num=num/10;
        }
    return count;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    Solution solution;

    while(t--){
        int num;
        cout << "Enter the number: ";
        cin >> num;
        int result = solution.countDigits(num);
        cout << "Number of digits in " << num << " that divide it: " << result << endl;
    }

    return 0;

}