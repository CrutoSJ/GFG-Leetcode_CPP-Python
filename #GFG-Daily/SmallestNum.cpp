// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/smallest-number5829/1

// Date-> 15/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int makeS(int d){
        int ans = 1;
        while(d>1){
            ans = ans*10;
            d--;
        }
        return ans;
    }
    int makeE(int d){
        int ans = 1;
        while(d>0){
            ans = ans*10;
            d--;
        }
        return ans-1;
    }
    
    bool isSame(int i, int s){
        int sum = 0;
        while(i>0){
            int digit = i%10;
            sum += digit;
            i = i/10;
        }
        if(sum == s) return true;
        return false;
    }
    
public:
    string smallestNumber(int s, int d) {
        int start = makeS(d);
        int end = makeE(d);
        string ans;
        
        for(int i=start; i<=end; i++){
            if(isSame(i, s)){
                ans = to_string(i);
                return ans;
            }
        }
        
        return to_string(-1);
    }

    string smallestNumberOptimized(int s, int d) {
        if((d*9)<s) return "-1";
        string ans = "";
        for(int i = d-1; i>=0; i--){
            if(s>9){
                ans = '9'+ans;
                s -= 9;
            } else{
                if(i==0){
                    ans=to_string(s)+ans;
                } else{
                    ans=to_string(s-1)+ans;
                    i--;
                    while(i>0){
                        ans='0'+ans;
                        i--;
                    }
                    ans="1"+ans;
                    break;
                }
            }
        }
        return ans;
    }
};