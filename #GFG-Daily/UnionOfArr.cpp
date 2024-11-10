// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1

// Date-> 10/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> res;
        int i=0, j=0;
        
        while(i<a.size() && j<b.size()){
            if(a[i] == b[j]){
                res.push_back(a[i]);
                i++, j++;
            } else if(a[i]>b[j]){
                res.push_back(b[j]);
                j++;
            } else{
                res.push_back(a[i]);
                i++;
            }
        }
        
        while(i<a.size()){
            res.push_back(a[i]);
            i++;
        }
        
        while(j<b.size()){
            res.push_back(b[j]);
            j++;
        }
        
        return res;
    }
};