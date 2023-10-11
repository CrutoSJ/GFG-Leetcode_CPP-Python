// #Question:-

// There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.

// A city's skyline is the outer contour formed by all the building when viewing the side of the city from a distance. The skyline from each cardinal direction north, east, south, and west may be different.

// We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). The height of a 0-height building can also be increased. However, increasing the height of a building should not affect the city's skyline from any cardinal direction.

// Return the maximum total sum that the height of the buildings can be increased by without changing the city's skyline from any cardinal direction.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> rows(n), cols(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += min(rows[i], cols[j]) - grid[i][j];
            }
        }
        
        return res;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the value of n: ";
        cin >> n;
        
        vector<vector<int>> grid(n, vector<int>(n));
        cout << "Enter the grid values:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        Solution solution;
        int maxIncrease = solution.maxIncreaseKeepingSkyline(grid);
        cout << "Maximum total sum that the height of the buildings can be increased by: " << maxIncrease << endl;
    }
    
    return 0;
}