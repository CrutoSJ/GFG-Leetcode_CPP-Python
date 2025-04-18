// #Question:-

// Link-> https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18

// Date-> 18/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
         string countAndSay(int n) {
            vector<string> uttar;
            string a="";
            uttar.push_back(a);
            for(int i=1;i<=n;i++){
                a=uttar[i-1];
                if(a=="") uttar.push_back("1");
                else{
                    string ans="";
                    int count=1,flag=1;
                    for(int i=0;i<a.size()-1;++i){
                        if(a[i+1]==a[i]){
                            count++;
                        }
                        else{
                            ans+=(count+'0');
                            ans+=a[i];
                            count=1;
                        }  
                    }
                    if(flag==1){
                        ans+=(count+'0');
                        ans+=a[a.size()-1];
                    }
                    uttar.push_back(ans);
                }
            }
            return uttar[n];
        }
    };