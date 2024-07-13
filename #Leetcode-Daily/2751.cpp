// #Question:-

// Link-> https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13

// Date-> 13/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int>actual_idx(n);
        iota(actual_idx.begin(), actual_idx.end(), 0);

        auto lambda = [&](int &i, int &j){
            return positions[i]<positions[j];
        };

        sort(actual_idx.begin(), actual_idx.end(), lambda);

        vector<int>result;
        stack<int>st;

        for(int &i : actual_idx){
            if(directions[i] == 'R'){
                st.push(i);
            } 
            else{
                while(!st.empty() && healths[i] > 0){
                    int opn = st.top();
                    st.pop();
                    if(healths[i] < healths[opn]){
                        healths[i] = 0;
                        healths[opn] -= 1;
                        st.push(opn);
                    } else if(healths[i] > healths[opn]){
                        healths[opn] = 0;
                        healths[i] -= 1;
                    } else{
                        healths[opn] = 0;
                        healths[i] = 0;
                    }
                }
            }
        }

        for(int &i : healths){
            if(i > 0){
                result.push_back(i);
            }
        }

        return result;
    }
};