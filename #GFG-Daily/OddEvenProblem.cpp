// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/help-nobita0532/1

//Date -> 01/06/24 

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string oddEven(string s) {
        int x=0, y=0;
        vector<int>count(27,0);
        
        for(int i=0; i<s.size(); i++){
            count[s[i]-'a'+1]++;
        }
        
        for(int i=1; i<27; i++){
            if(count[i]!=0 && count[i]%2==0 && i%2==0){
                x++;
            } 
            else if(count[i]%2==1 && i%2==1){
                y++;
            }
        }
        
        int sum = x+y;
        if(sum%2==0) return "EVEN";
        else return "ODD";
    }
};