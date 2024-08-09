// #Question:-

// Link-> https://leetcode.com/problems/magic-squares-in-grid/?envType=daily-question&envId=2024-08-09

// Date-> 09/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int checkRow(vector<vector<int>>& grid, int r, int c){
        unordered_map<int, bool> visited;
        int sum = 0;
        for(int i=0; i<3; i++){
            int rowSum = 0;
            for(int j=0; j<3; j++){
                int val = grid[r+i][c+j];
                if(val<1 || val>9 || visited[val] == true){
                    return -1;
                }
                visited[val] = true;
                rowSum += val;
            }
            if(i==0){
                sum = rowSum;
            } else if(sum != rowSum){
                return -1;
            }
        }
        return sum;
    }

    int checkCol(vector<vector<int>>& grid, int r, int c){
        int sum = 0;
        for(int j=0; j<3; j++){
            int colSum = 0;
            for(int i=0; i<3; i++){
                int val = grid[r+i][c+j];
                colSum += val;

            }
            if(j==0){
                sum = colSum;
            } else if(sum != colSum){
                return -1;
            }
        }
        return sum;
    }

    int checkDia(vector<vector<int>>& grid, int r, int c){
        int sum1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int sum2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];

        if(sum1!=sum2){
            return -1;
        }
        return sum1;
    }

    bool isMagicSquare(vector<vector<int>>& grid, int i, int j){
        int rowSum = checkRow(grid, i, j);
        if(rowSum == -1){
            return false;
        }
        int colSum = checkCol(grid, i, j);
        if(colSum == -1){
            return false;
        }
        int diagonalSum = checkDia(grid, i, j);
        if(diagonalSum == -1){
            return false;
        }
        if(rowSum == colSum && rowSum == diagonalSum){
            return true;
        } else{
            return false;
        }
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rSize = grid.size();
        int cSize = grid[0].size();
        int cnt=0;
        for(int i=0; i<rSize-2; i++){
            for(int j=0; j<cSize-2; j++){
                if(isMagicSquare(grid, i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};