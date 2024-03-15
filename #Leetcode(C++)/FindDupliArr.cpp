// #Question:-

// Link->  https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1?page=1&sortBy=submissions

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> duplicates(long long arr[], int n) {
        vector<int>count(n,0);
        for(int i=0; i<n; i++){
            count[arr[i]]++;
        }
        
        set<int>ans;
        for(int i=0; i<n; i++){
            if(count[i]>1){
                ans.insert(i);
            }
        }
        if(ans.empty()){
            ans.insert(-1);
        }
        vector<int>res(ans.begin(),ans.end());
        return res;
    }
};