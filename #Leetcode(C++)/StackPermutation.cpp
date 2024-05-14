// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/stack-permutations/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
    int j = 0;
    
    for (int i = 0; i < N; i++) {
        s.push(A[i]);
        while (!s.empty() && s.top() == B[j]) {
            s.pop();
            j++;
        }
    }
    
    if (s.empty()) { 
        return true;
    }
    return false;
    }
};