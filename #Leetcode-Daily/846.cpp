// #Question:-

// Link-> https://leetcode.com/problems/hand-of-straights/

// Date - 06/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gS) {
        int n = hand.size();
        if(n%gS != 0) return false;
        unordered_map<int,int>count;
        sort(hand.begin(),hand.end());
        for(int i=0; i<n; i++){
            count[hand[i]]++;
        }
        
        int i=0, group=0;
        while(i<n){
            int occ=0, curr=hand[i];
            while(occ<gS && count.find(curr)!=count.end()){
                if(count[curr]==1){
                    count.erase(curr);
                } else{
                    count[curr]--;
                }
                occ++;
                curr++;
            }
            
            if(occ==gS){
                group++;
            }
            i++;
        }
        return group==n/gS;
    }
};