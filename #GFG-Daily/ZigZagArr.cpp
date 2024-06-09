// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

// Date -> 09/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void zigZag(int n, vector<int> &arr) {
        for(int i=0; i<n-1; i++){
            if(i%2==0){
                if(arr[i]>arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }
            else{
                if(arr[i]<arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }
        }
        return ;
    }
};
