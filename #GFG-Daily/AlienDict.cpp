// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/alien-dictionary/1

// Date-> 22/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void findTopoSort(int k, unordered_map<int, vector<int>> &adj, vector<int> &topo){
        vector<int> inDegree(k,0);
        for(int i=0; i<k; i++){
            for(auto &j : adj[i]){
                inDegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<k; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            topo.push_back(front);
            
            for(auto &nbr : adj[front]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        return ;
    }
  public:
    string findOrder(string dict[], int n, int k) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n-1; i++){
            string str1 = dict[i];
            string str2 = dict[i+1];
            int len = min(str1.size(), str2.size());
            for(int j=0; j<len; j++){
                if(str1[j] != str2[j]){
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo;
        findTopoSort(k, adj, topo);
        string ans = "";
        for(auto &it : topo){
            ans = ans + char(it + 'a');
        }
        
        return ans;
    }
};