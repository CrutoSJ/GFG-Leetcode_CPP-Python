// #Question:-

// Link-> https://leetcode.com/problems/sliding-puzzle/description/?envType=daily-question&envId=2024-11-25

// Date-> 25/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }

        string target = "123450";

        unordered_map<int, vector<int>> swaps;
        swaps[0] = {1, 3};
        swaps[1] = {0, 2, 4};
        swaps[2] = {1, 5};
        swaps[3] = {0, 4};
        swaps[4] = {1, 3, 5};
        swaps[5] = {2, 4};

        queue<string> q;
        q.push(start);

        unordered_set<string> vis;
        vis.insert(start);

        int lvl = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == target){
                    return lvl;
                }

                int zeroIdx = curr.find('0');
                for(int &swapIdx : swaps[zeroIdx]){
                    string newCurr = curr;
                    swap(newCurr[swapIdx], newCurr[zeroIdx]);
                    if(vis.find(newCurr) == vis.end()){
                        q.push(newCurr);
                        vis.insert(newCurr);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};