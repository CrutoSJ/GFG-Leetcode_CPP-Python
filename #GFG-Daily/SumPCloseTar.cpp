// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1

// Date-> 06/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int low=0, high=arr.size()-1, cloDif=INT_MAX;
        int fst=-1,sec=-1;
        
        while(low<high){
            int sum    = arr[low]+arr[high];
            int curDif = abs(sum-target);
            
            if(curDif<cloDif || (curDif==cloDif && (arr[high]-arr[low] > sec-fst))){
                fst=arr[low];
                sec=arr[high];
                cloDif=curDif;
            }
            
            if(sum<target){
                low++;
            } else{
                high--;
            }
        }
        return (fst==-1 && sec==-1) ? vector<int> {} : vector<int>{fst,sec};
    }
};