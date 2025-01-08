// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

// Date-> 08/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans=0;
        
        for(int i=arr.size()-1; i>=2; i--){
            int j=0, k=i-1;
            while(j<k){
                int sum = arr[j]+arr[k];
                if(sum>arr[i]){
                    ans+=k-j;
                    k--;
                }else{
                    j++;   
                }
            }
        }
        return ans;
    }
};