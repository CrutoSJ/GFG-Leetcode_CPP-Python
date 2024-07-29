// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

// Date-> 29/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int m = arr.size();
        int n = arr[0].size();
        int ansRow = -1;
        int i=0, j=n-1;
        
        while(i<m && j>=0){
            if(arr[i][j] == 1){
                ansRow = i;
                j--;
            }
            else{
                i++;
            }
        }
        return ansRow;
    }
};