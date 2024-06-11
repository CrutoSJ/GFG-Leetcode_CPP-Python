// #Question:-

// Link-> https://leetcode.com/problems/relative-sort-array/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    //Counting sort approach :-

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int max_ele = *max_element(arr1.begin(), arr1.end());
        vector<int>count(max_ele+1);
        
        for(int i:arr1){
            count[i]++;
        }
        
        vector<int>ans;
        
        for(int i:arr2){
            while(count[i]>0){
                ans.push_back(i);
                count[i]--;
            }
        }
        
        for(int i=0 ; i<=max_ele; i++){
            while(count[i]!=0){
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }

    //Using Hash Map:-
    vector<int> relativeSortArray2(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>count;
        vector<int>ans;
        for(int i=0; i<arr1.size();i++){
            count[arr1[i]]++;
        }
        
        for(int i=0; i<arr2.size(); i++){
            for(auto j=count.begin(); j!=count.end(); ++j){
                if(arr2[i]==j->first){
                    while(j->second!=0){
                        ans.push_back(j->first);
                        j->second--;
                    }
                }
            }
        }
        
        for(auto i=count.begin(); i!=count.end(); ++i){
            while(i->second!=0){
                ans.push_back(i->first);
                i->second--;
            }
        }
        return ans;
    }
};