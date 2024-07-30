// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Date-> 30/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSafe(int newR, int newC, vector<vector<int>> &mat, vector<vector<int>> &visited){
        /*2 checks:-
        1) next is 1
        2) not visited
        */
        
        int n = mat.size();
        
        if( (newR>=0 && newR<n) && (newC>=0 && newC<n) && (mat[newR][newC] == 1) && (visited[newR][newC] != 1)){
            return true;
        } else{
            return false;
        }
    }

    void solve(int row, int col, vector<vector<int>> &mat, vector<string> &ans, vector<vector<int>> &visited, int n, string path){
        if(row == n-1 && col == n-1){
            ans.push_back(path);
        }
        
        /*4 movements:-
        1) Down
        2) Left
        3) Right
        4) Up
        */
        
        visited[row][col] = 1;
        
        //1st Down:- (row++, col)
        if(isSafe(row+1, col, mat, visited)){
            solve(row+1, col, mat, ans, visited, n, path+'D');
        }
        //Left
        if(isSafe(row, col-1, mat, visited)){
            solve(row, col-1, mat, ans, visited, n, path+'L');
        }
        //Right
        if(isSafe(row, col+1, mat, visited)){
            solve(row, col+1, mat, ans, visited, n, path+'R');
        }
        //Up
        if(isSafe(row-1, col, mat, visited)){
            solve(row-1, col, mat, ans, visited, n, path+'U');
        }
        
        visited[row][col] = 0;
    }
public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        if(mat[0][0] == 0){
            return ans;
        }
        int n = mat.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        string path = "";
        solve(0, 0, mat, ans, visited, n, path);
        return ans;
    }
};
