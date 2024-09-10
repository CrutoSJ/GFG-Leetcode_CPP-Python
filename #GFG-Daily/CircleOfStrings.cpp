// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/circle-of-strings4530/1

// Date-> 10/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        int s = arr.size();
        vector<int> indegree(26,0);
        vector<int> outdegree(26,0);
        unordered_map<int, bool> vis;
        unordered_map<char, vector<int>> idx;
        queue<int> q;
        
        for(int i=0; i<s; i++){
            indegree[arr[i][0] - 'a']++;
            outdegree[arr[i].back() -'a']++;
            idx[arr[i][0]].push_back(i);
        }
        
        for(auto &x: arr){
            if(indegree[x[0]-'a'] != outdegree[x[0]-'a']){
                return 0;
            }
        }
        
        q.push(0);
        vis[0] = true;
        int count = 1;
        
        while(!q.empty()){
            int index = q.front();
            q.pop();
            
            for(auto &nbr : idx[arr[index].back()]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    count++;
                    q.push(nbr);
                }
            }
        }
        
        return count==s;
        
    }
};