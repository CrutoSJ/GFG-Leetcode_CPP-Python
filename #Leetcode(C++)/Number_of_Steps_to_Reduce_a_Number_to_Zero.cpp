// Question:-

// Given an integer num, return the number of steps to reduce it to zero.

// In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num>0){
            if(num%2!=0){
                num=num-1;
            }
            else{
                num = num/2;
            }
            count++;
        }
        return count;
    }
};

int main(){
    int t;
    cout << "Enter no of test cases: ";
    cin >> t;

    Solution solution;
    while(t--){
        int num;
        cout << "Enter the number: ";
        cin >> num;

        int steps = solution.numberOfSteps(num);
        cout << "Number of steps to reduce " << num << " to zero: " << steps << endl;
    }

    return 0;

}