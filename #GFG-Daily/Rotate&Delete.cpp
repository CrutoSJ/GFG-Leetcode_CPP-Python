// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1

// Date-> 02/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int sz = arr.size()/2;
        int k = 1;
        while(k <= sz){
            arr.insert(arr.begin(), arr.back());
            arr.pop_back();
            arr.erase(arr.end()-k);
            k++;
        }
        
        return arr[0];
    }
};