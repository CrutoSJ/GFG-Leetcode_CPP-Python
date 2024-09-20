// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/facing-the-sun2126/1

// Date-> 20/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int count = 0;
        int limit = INT_MIN;
        
        for(auto &x : height){
            if(x>limit){
                count++;
                limit=x;
            }
        }
        
        return count;
    }
};