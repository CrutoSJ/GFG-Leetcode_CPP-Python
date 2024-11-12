// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/attend-all-meetings/1

// Date-> 12/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());
        
        for(int i=1; i<arr.size(); i++){
            int startCurr = arr[i][0];
            int endPrvs   = arr[i-1][1];
            if(endPrvs>startCurr){
                return false;
            }
        }
        return true;
    }
};