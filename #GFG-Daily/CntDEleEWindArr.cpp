// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

// Date-> 10/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n=arr.size(), j=0;
        vector<int> ans;
        unordered_map<int,int> freq;
        
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
            if(i>=k-1){
                ans.push_back(freq.size());
                freq[arr[j]]--;
                if(freq[arr[j]] == 0){
                    freq.erase(arr[j]);
                }
                j++;
            }
        }
        return ans;
    }
};