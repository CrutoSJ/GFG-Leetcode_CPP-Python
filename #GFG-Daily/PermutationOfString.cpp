// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

// Date-> 28/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> findPermutation(string &s) {
        vector<string> res;
        sort(s.begin(), s.end());
        
        do{
            res.push_back(s);
        } while(next_permutation(s.begin(), s.end()));
        return res;
    }
};