// #Question:-

// Link-> https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/?envType=daily-question&envId=2024-09-22

// Date-> 22/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int CountNum(long curr, long next, int n){
        int countNum = 0;

        while(curr <= n){
            countNum += (next-curr);

            curr *= 10;
            next *= 10;

            next = min(next, long(n+1));
        }

        return countNum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;

        while(k>0){
            int count = CountNum(curr, curr+1, n);

            if(count <= k){
                curr++;
                k -= count;
            } else{
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};