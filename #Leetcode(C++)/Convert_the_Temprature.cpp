// Question:-

// You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.

// You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].

// Return the array ans. Answers within 10-5 of the actual answer will be accepted.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        ans.push_back(celsius+273.15);
        ans.push_back((celsius*1.80)+32);
     return ans;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    Solution solution;
    while(t--){
        double celsius;
        cout << "Enter temperature in Celsius: ";
        cin >> celsius;

        vector<double> result = solution.convertTemperature(celsius);
        cout << "Kelvin: " << result[0] << endl;
        cout << "Fahrenheit: " << result[1] << endl;
    }

    return 0;

}