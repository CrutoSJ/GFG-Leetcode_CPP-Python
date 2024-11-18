// #Question:-

// Link-> https://leetcode.com/problems/defuse-the-bomb/description/?envType=daily-question&envId=2024-11-18

// Date-> 18/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> res(n,0);
        if(k == 0){
            return res;
        }

        int i=-1, j=-1;

        if(k>0){
            i=1, j=k;
        } else{
            i=n-abs(k);
            j=n-1;
        }

        int sum = 0;
        for(int idx=i; idx<=j; idx++){
            sum += code[idx];
        }

        for(int k=0; k<n; k++){
            res[k] = sum;

            sum -= code[i % n];
            i++;

            sum += code[(j+1) % n];
            j++;
        }

        return res;
    }
};