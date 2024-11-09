// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-sum4058/1

// Date-> 09/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string minSum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string num1 = "" , num2 = "";
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                num1 += '0'+arr[i]; 
            } else{
                num2 += '0'+arr[i];
            }
        }
        
        string res = "";
        int s1 = num1.size(), s2 = num2.size();
        int i=s1-1, j=s2-1, carry=0;
        
        while(i>-1 || j>-1 || carry){
            int temp1 = i>-1 ? num1[i]-'0' : 0;
            int temp2 = j>-1 ? num2[j]-'0' : 0;
            int num = temp1+temp2+carry;
            res += '0'+num%10;
            carry = num/10;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        int idx = 0;
        for(idx=0; idx<res.length(); idx++){
            if(res[idx] != '0'){
                break;
            }
        }
        return res.substr(idx);
    }
};