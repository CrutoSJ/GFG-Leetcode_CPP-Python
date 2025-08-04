// #Question:-

// Link-> https://leetcode.com/problems/fruit-into-baskets/description/?envType=daily-question&envId=2025-08-04

// Date-> 04/08/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
           int t1=0,t2=-1;
           int maxi=1,st=0;
           for(int i=1;i<fruits.size();i++){
                if(fruits[i]==fruits[t1]){
                    t1=i;
                }
                else if(t2==-1 || fruits[i]==fruits[t2]){
                    t2=i;
                }
                else{
                    maxi=max(maxi,i-st);
                    st=min(t1,t2)+1;
                    t1=max(t1,t2);
                    t2=i;
                }
           }
           return max(maxi,(int)fruits.size()-st);

    }
};