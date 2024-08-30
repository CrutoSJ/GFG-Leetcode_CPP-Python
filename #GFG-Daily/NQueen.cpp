// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

// Date-> 30/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
bool isSafe(int row, int col,  vector<vector<int>> &board, int n){
    int x = row;
    int y = col;
    
    while(y>=0){//check for that row in diff col
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    
    //check for upper - left diagonal
    x = row;
    y = col;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    
    //check for lower-left diagonal
    x = row;
    y = col;
    while(x<n && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}
    void addAns(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
        vector<int> temp;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[j][i] == 1){
                    temp.push_back(j+1);
                }
            }
        }
        
        ans.push_back(temp);
    }
    void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n){
        if(col == n){
            addAns(board, ans, n);
            return ;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                solve(col+1, board, ans, n);
                board[row][col] = 0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>board(n, vector<int>(n,0));
        vector<vector<int>>ans;

        solve(0, board, ans, n);
        
        return ans;
    }
};