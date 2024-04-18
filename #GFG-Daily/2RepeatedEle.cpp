// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        vector<int>count(n+1);
        vector<int>repeat(2);
        int j=0;
        for(int i=0; i<n+2; i++){
            count[arr[i]]++;
            if(count[arr[i]]==2){
                repeat[j]=arr[i];
                j++;
            }
        }
        
        return repeat;
    }
};