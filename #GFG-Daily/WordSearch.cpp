// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

// Date-> 01/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        for(int i =0; i<mat.size(); i++){
            for(int j =0; j<mat[0].size(); j++){
                if(mat[i][j]==word[0]){
                  vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
                  if(check(mat, i, j , 0 , word , visit)){
                      return true;
                  }

                }
            }
        }
        return false;
    }
    
    private:
    bool check(vector<vector<char>>& mat, int i, int j, int idx,  string& word ,  vector<vector<bool>>&visit)
   {
    
    if(idx == word.size()){
        return true;
    }
    
    if(i<0 || j<0 || i>=mat.size()||  j>=mat[0].size() || visit[i][j] || mat[i][j]!= word[idx]){
        return false;
    }
    visit[i][j] = true;
    
    if(check(mat , i,  j-1, idx+1 , word, visit )||  //left
     check(mat , i,  j+1, idx+1 , word, visit )|| //right
     check(mat , i-1,  j, idx+1 , word, visit )|| //up
     check(mat , i+1,  j, idx+1 , word, visit )) //down
     {
         return true;
     }
     visit[i][j] = false;
     return false;
    }
};
