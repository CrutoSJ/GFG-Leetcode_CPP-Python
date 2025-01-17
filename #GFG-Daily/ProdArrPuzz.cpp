// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

// Date-> 17/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int temp=1, cnt=0, idx=-1, n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i])temp*=arr[i];
            else{
                cnt++;
                idx=i;
            }
        }
        vector<int> res(n,0);
        if(cnt>1)return res;
        if(cnt==1){
            res[idx]=temp;
            return res;
        }
        for(int i=0; i<n; i++){
            res[i]=temp/arr[i];
        }
        return res;
    }
};