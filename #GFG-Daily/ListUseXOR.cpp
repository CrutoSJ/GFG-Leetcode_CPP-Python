// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

// Date-> 02/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructList(int q, vector<vector<int>> &arr) {
        vector<int>ans;
        int x = 0;
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i][0] == 0){
                ans.push_back(x^arr[i][1]);
            } else{
                x^= arr[i][1];
            }
        }
        ans.push_back(x^0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};