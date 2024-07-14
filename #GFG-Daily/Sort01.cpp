// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

// Date-> 14/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int i=0, j=arr.size()-1;
        while(i<=j){
            if(arr[i]==0){
                i++;
            }
            else if(arr[j]==1){
                j--;
            }
            else if(arr[i] == 1 && arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            else{
                i++;
                j--;
                
            }
        }
        return;
    }
};