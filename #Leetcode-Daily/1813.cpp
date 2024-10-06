// #Question:-

// Link-> https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06

// Date-> 06/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()){
            swap(s1,s2);
        }

        vector<string> vec1;
        vector<string> vec2;

        stringstream ss1(s1);
        string token;
        while(ss1 >> token){
            vec1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token){
            vec2.push_back(token);
        }

        int i=0, j=vec1.size()-1;
        int l=0, k=vec2.size()-1;

        while(i<vec1.size() && l<vec2.size() && vec1[i] == vec2[l]){
            i++, l++;
        }

        while(l<=k && vec1[j] == vec2[k]){
            j--, k--;
        }

        return l>k;
    }
};