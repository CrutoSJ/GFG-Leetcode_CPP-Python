// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1

// Date-> 21/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9+7;
    long long int findMaxProduct(vector<int>& arr) {
        if(arr.size() == 1) return arr[0];
        long long zeroCnt = 0, posCnt = 0, negCnt = 0, product = 1, maxi = INT_MIN;
        for(int i=0;i<arr.size(); i++){
            if(arr[i]!=0){
                product = (1LL*product*arr[i])%MOD;
                if(arr[i]<0){
                    negCnt++;
                    maxi = max(maxi,(1LL*arr[i]));
                } else{
                    posCnt++;
                }
            }else{
                zeroCnt++;
            }
        }
        if(zeroCnt==arr.size()) return 0;
        if(posCnt == 0 && negCnt == 1) return 0;
        if(product < 0) product/=maxi;
        return (1LL * product)%MOD;
    }
};