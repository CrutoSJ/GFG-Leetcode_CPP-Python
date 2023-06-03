// Question:-

// You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

// A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

// Solution:-

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            for (int j = 0; j < accounts[0].size(); j++) {
                sum += accounts[i][j];
            }
            max = std::max(sum, max);
        }
        return max;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while (t--) {
        int m, n;
        cout << "Enter no. of customers: ";
        cin >> m;
        cout << "Enter no. of banks: ";
        cin >> n;
        
        vector<vector<int>> accounts(m, vector<int>(n));
        
        cout << "Enter wealth of each customer for each bank:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> accounts[i][j];
            }
        }
        
        Solution s;
        int maxWealth = s.maximumWealth(accounts);
        cout << "Maximum wealth: " << maxWealth << endl;
    }

    return 0;
}
