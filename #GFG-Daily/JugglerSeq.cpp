// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/juggler-sequence3930/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> jugglerSequence(long long n) {
        vector<long long>ans;
    ans.push_back(n);
    while(n!=1){
        if(n%2==0){
            n=sqrt(n);
            
        }

        else{
            n=n*sqrt(n);
        }
        ans.push_back(n);
    }
    return ans;
    }
};