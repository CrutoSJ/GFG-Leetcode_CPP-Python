// #Question:-

// Link -> https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

// Date -> 09/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n=colors.size()+k-1;
            int i=0, j=1, res=0;
    
            for(int i=0; i<k-1; i++){
                colors.push_back(colors[i]);
            }
    
            while(j<n){
                if(colors[j]==colors[j-1]){
                    i=j;
                }
    
                if(j-i+1==k){
                    res++;
                    i++;
                }
                j++;
            }
            return res;
        }
    };