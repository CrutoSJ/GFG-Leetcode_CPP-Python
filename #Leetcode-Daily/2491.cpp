// #Question:-

// Link-> https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04

// Date-> 04/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n =  skill.size();
        sort(skill.begin(), skill.end());
        
        int i = 0; 
        int j = n-1;
        int sum = skill[i] + skill[j];
        long long chem = 0;

        while(i<j){
            if(skill[i] + skill[j] != sum){
                return -1;
            }

            chem += (skill[i] * skill[j]);
            i++, j--;
        }
        return chem;
    }
};