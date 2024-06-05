// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

// Date -05/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sumA=0, sumB=0;
        for(int i=0; i<n; i++) sumA+=a[i];
        for(int i=0; i<m; i++) sumB+=b[i];
        
        if((sumA-sumB)%2 != 0) return -1;
        
        sort(a, a+n);
        sort(b, b+m);
        
        int i=0,j=0;
        int target = (sumA-sumB)/2;
        
        while(i<n && j<m){
            int diff = a[i]-b[j];
            if(diff == target) return 1;
            else if(diff<target) i++;
            else j++;
        }
        
        return -1;
    }
};