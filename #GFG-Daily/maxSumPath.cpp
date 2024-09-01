// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1

// Date-> 01/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int maxSum=0;
        int sum1  =0;
        int sum2  =0;
        
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i] == arr2[j]){
                maxSum+=max(sum1,sum2) + arr1[i];
                sum1=0,sum2=0;
                i++,j++;
            }
            else if(arr1[i] < arr2[j]){
                sum1+=arr1[i];
                i++;
            }
            else if(arr1[i] > arr2[j]){
                sum2+=arr2[j];
                j++;
            }
        }
        
        while(i<arr1.size()){
            sum1+=arr1[i];
            i++;
        }
        while(j<arr2.size()){
            sum2+=arr2[j];
            j++;
        }
        
        maxSum+=max(sum1,sum2);
        return maxSum;
    }
};