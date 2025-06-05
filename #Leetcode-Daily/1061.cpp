// #Question:-

// Link-> https://leetcode.com/problems/lexicographically-smallest-equivalent-string/?envType=daily-question&envId=2025-06-05

// Date-> 05/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Disjoint{
public:
    vector<int>par;
    vector<int>size;

    Disjoint(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }
    int findPar(int u){
        if(par[u] == u)return u;
        return par[u] = findPar(par[u]);
    }
    void merge(int u, int v){
        int par_u = findPar(u);
        int par_v = findPar(v);
        if(par_u == par_v)return;
        if(par_u < par_v){
            par[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            par[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        Disjoint ds(26);
        for(int i=0; i<n; i++){
            ds.merge(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(auto &it : baseStr){
            char x = 'a' + ds.findPar(it-'a');
            ans.push_back(x);
        }
        for(auto &it : ds.par){
            cout << it << " ";
        }
        return ans;
    }
};