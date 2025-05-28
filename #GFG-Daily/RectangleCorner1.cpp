// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

// Date-> 28/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int, set<int>> mp;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int j2=j+1; j2<m; j2++){
                    if(mat[i][j] == 1 && mat[i][j2]==1){
                        if(mp.find(j)!=mp.end() && mp[j].find(j2)!=mp[j].end()){
                            return true;
                        }
                        else  mp[j].insert(j2);
                        
                    }
                }
            }   
        }
        return false;
    }
};