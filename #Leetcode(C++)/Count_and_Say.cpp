// Question:-

// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":

// Solution:-

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> uttar;
        string a = "";
        uttar.push_back("");
        for (int i = 1; i <= n; i++) {
            a = uttar[i - 1];
            if (a == "")
                uttar.push_back("1");
            else {
                string ans = "";
                int count = 1;
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i + 1] == a[i]) {
                        count++;
                    } else {
                        ans += to_string(count);
                        ans += a[i];
                        count = 1;
                    }
                }
                ans += to_string(count);
                ans += a[a.size() - 1];
                uttar.push_back(ans);
            }
        }
        return uttar[n];
    }
};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter the value of n: ";
        cin >> n;
        Solution obj;
        string result = obj.countAndSay(n);
        cout << "Count and Say sequence for n = " << n << ": " << result << endl;
    }
    return 0;
}