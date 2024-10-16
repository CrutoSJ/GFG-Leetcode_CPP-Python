// #Question:-

// Link-> https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16

// Date-> 16/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }

        string res = "";

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int currCnt  = top.first;
            char currChar = top.second;

            if(res.length()>=2 && res[res.length()-1] == currChar && res[res.length()-2] == currChar){
                if(pq.empty()){
                    break;
                }

                auto top2 = pq.top();
                pq.pop();

                int newCnt  = top2.first;
                char newChar = top2.second;

                res.push_back(newChar);
                newCnt--;

                if(newCnt>0){
                    pq.push({newCnt, newChar});
                }
            } else{
                res.push_back(currChar);
                currCnt--;
            }

            if(currCnt>0){
                pq.push({currCnt, currChar});
            }
        }
        return res;
    }
};