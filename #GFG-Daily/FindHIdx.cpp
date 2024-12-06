// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-h-index--165609/1

// Date-> 06/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int res = n;
        
        for(int i=0; i<n; i++){
            if(citations[i] >= res){
                return res;
            }
            res--;
        }
        
        return 0;
    }
};