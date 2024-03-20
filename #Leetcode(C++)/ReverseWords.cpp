// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/reverse-words_7037425

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

string revWords(string str) {
    int n=str.length();
    string res="";
    int i=0;
    while(i<n){
        while(i<n&&str[i]==' '){
            i++;
        }
        if(i>=n)break;
        int j=i+1;
        while(j<n&&str[j]!=' '){
            j++;
        }
        string sub = str.substr(i,j-i);
        if(res.length()==0){
            res=sub;
        }
        else{
            res=sub+" "+res;
        }
        i=j+1;
    }
    return res;
}