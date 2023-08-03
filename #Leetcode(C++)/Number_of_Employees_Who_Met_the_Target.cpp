// #Question:-

// There are n employees in a company, numbered from 0 to n - 1. Each employee i has worked for hours[i] hours in the company.

// The company requires each employee to work for at least target hours.

// You are given a 0-indexed array of non-negative integers hours of length n and a non-negative integer target.

// Return the integer denoting the number of employees who worked at least target hours.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        
        int ans = 0;

        for(auto x : hours)
        {
            if( x >= target) ans+=1;
        }

        return ans;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n, target;
        cout << "Enter the number of employees: ";
        cin >> n;
        vector<int> hours(n);
        cout << "Enter the hours worked by each employee:\n";
        for (int i = 0; i < n; ++i) {
            cin >> hours[i];
        }
        cout << "Enter the target hours: ";
        cin >> target;

        Solution obj;
        int result = obj.numberOfEmployeesWhoMetTarget(hours, target);
        cout << "Number of employees who worked at least " << target << " hours: " << result << "\n";
    }
    return 0;

}