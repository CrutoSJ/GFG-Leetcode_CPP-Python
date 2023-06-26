// Question:-

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of the matrix: ";
        cin >> n;
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        cout << "Enter the elements of the matrix: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        
        Solution obj;
        obj.rotate(matrix);
        
        cout << "Rotated matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;

}
