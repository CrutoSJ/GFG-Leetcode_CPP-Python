// #Question:-

// Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

// There is one laser beam between any two security devices if both conditions are met:

// The two devices are located on two different rows: r1 and r2, where r1 < r2.
// For each row i where r1 < i < r2, there are no security devices in the ith row.
// Laser beams are independent, i.e., one beam does not interfere nor join with another.

// Return the total number of laser beams in the bank.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0,x=0,y=0;
        for(auto &i: bank){
            for(auto &j: i){
                if(j=='1')x++;
            }
            if(x){
                ans += (x*y);
                y = x;
                x = 0;
            }
        }
        return ans;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int m, n;
        cout << "Enter number of rows and columns: ";
        cin >> m >> n;

        vector<string> bank(m);
        cout << "Enter the binary string array (row-wise):" << endl;
        for (int i = 0; i < m; i++)
            cin >> bank[i];

        Solution obj;
        int result = obj.numberOfBeams(bank);
        cout << "Total number of laser beams in the bank: " << result << endl;
    }

    return 0;
}