// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

// Date-> 10/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*

    ********** Did this using Sort Function ************

    */
    void matchPairs(int n, char nuts[], char bolts[]) {
        sort(nuts,nuts+n);
        sort(bolts,bolts+n);
        
    }

    /*

    ********** Did this using Ordered Map ************

    */
    void matchPairsTwo(int n, char nuts[], char bolts[]) {
        map<char,int>order;
        for(int i=0; i<n; i++){
            order[nuts[i]]++;
        }
        
        int i=0;
        for(auto it=order.begin(); it!=order.end(); ++it){
            if(i<n && it->second>0){
                nuts[i] = it->first;
                bolts[i] = it->first;
                i++;
                it->second--;
            }
        }
    }
};