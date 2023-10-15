// #Question:-

// A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

// Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        int row=mat.size();
        int col=mat[0].size();
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mp[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mat[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat ;     
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int m, n;
        cout << "Enter the number of rows and columns (m and n): ";
        cin >> m >> n;

        vector<vector<int>> mat(m, vector<int>(n, 0));
        cout << "Enter the elements of the matrix:" << endl;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        Solution solution;
        vector<vector<int>> sortedMat = solution.diagonalSort(mat);

        cout << "Sorted matrix diagonals:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << sortedMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}