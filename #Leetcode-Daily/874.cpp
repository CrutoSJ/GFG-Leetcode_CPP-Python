// #Question:-

// Link-> https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2024-09-04

// Date-> 04/09/24

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(vector<int> &obs : obstacles){
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxD = 0;

        pair<int,int> dir = {0,1};

        for(int i=0; i<commands.size(); i++){
            if(commands[i] == -2){
                dir = {-dir.second, dir.first};
            } else if(commands[i] == -1){
                dir = {dir.second, -dir.first};
            } else{
                for(int steps=0; steps<commands[i]; steps++){
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string newKey = to_string(newX) + "_" + to_string(newY);

                    if(st.find(newKey) != st.end()){
                        break;
                    }

                    x = newX;
                    y = newY;
                }
            }

            maxD = max(maxD, x*x + y*y);
        }

        return maxD;
    }
};