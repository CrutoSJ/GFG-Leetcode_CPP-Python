// Question:-

// Given a valid (IPv4) IP address, return a defanged version of that IP address.

// A defanged IP address replaces every period "." with "[.]".

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string temp{};
        int n = address.size();
        for (int i = 0; i < n; i++) {
            if (address[i] == '.') {
                temp += "[.]";
            } else {
                temp += address[i];
            }
        }
        return temp;
    }
};

int main() {
    string t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    int numCases = stoi(t);

    while (numCases--) {
        string n;
        cout << "Enter the size of array: ";
        cin >> n;

        int size = stoi(n);

        vector<string> address(size);
        for (int i = 0; i < size; i++) {
            cin >> address[i];
        }

        Solution solution;
        for (size_t i = 0; i < address.size(); i++) {
            string ans = solution.defangIPaddr(address[i]);
            cout << ans ;
        }
        cout << endl;
    }
    return 0;
}