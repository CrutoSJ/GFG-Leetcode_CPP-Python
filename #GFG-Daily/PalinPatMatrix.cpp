// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

// Date-> 28/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        for(int i=0; i<n; i++){
            bool isPali = true;
            for(int a=0, b=n-1; a<=b; a++,b--){
                if(arr[i][a] != arr[i][b]){
                    isPali = false;
                    break;
                }
            }
            if(isPali){
                return to_string(i) + " R"; 
            }
        }
        
        for(int i=0; i<n; i++){
            bool isPali = true;
            for(int a=0, b=n-1; a<=b; a++,b--){
                if(arr[a][i] != arr[b][i]){
                    isPali = false;
                    break;
                }
            }
            if(isPali){
                return to_string(i) + " C"; 
            }
        }
        return "-1";
    }
};