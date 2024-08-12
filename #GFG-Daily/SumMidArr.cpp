// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1

// Date-> 12/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int s = arr1.size();
        int i=0, j=0;
        vector<int> resArr;
        while(i<s && j<s){
            if(arr1[i] < arr2[j] || arr1[i] == arr2[j]){
                resArr.push_back(arr1[i]);
                i++;
            } else if(arr1[i] > arr2[j]){
                resArr.push_back(arr2[j]);
                j++;
            }
        }
        while(i<s){
            resArr.push_back(arr1[i]);
            i++;
        }
        while(j<s){
            resArr.push_back(arr2[j]);
            j++;
        }
        
        int n = resArr.size();
        
        if(n%2 == 0){
            return resArr[n/2-1] + resArr[n/2];
        } else{
            return resArr[n/2-1];
        }
    }
};