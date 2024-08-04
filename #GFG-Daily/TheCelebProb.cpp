// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// Date-> 03/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Function to find if there is a celebrity in the party or not.
        int celebrity(vector<vector<int> >& mat) {
            int n=mat.size();
            int celeb = 0;
            
            for(int i=1; i<n; i++){
                if(mat[celeb][i] == 1){
                    celeb = i;
                }
            }
            
            for(int i=0; i<n; i++){
                if(i != celeb && ( (mat[celeb][i] != 0) || (mat[i][celeb] != 1) )){
                    return -1;
                }
            }
            return celeb;
        }
};