// #Question:-

// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

// Solution:-


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int equalPairs(vector<vector<int>>& grid) {
        int n =grid.size();
        int a = 0;
        vector<vector<int>>copy=grid;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
            
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i]==copy[j])
                    a++;
            }
        }
        return a;
            
    }
};

int main(){
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while(t--){
        int n;
        cout << "Enter the size of the matrix: ";
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << "Enter element at (" << i << "," << j << "): ";
                cin >> grid[i][j];
            }
        }

        Solution obj;
        int result = obj.equalPairs(grid);
        cout << "The number of equal row-column pairs is: " << result << endl;
    }

    return 0;
}