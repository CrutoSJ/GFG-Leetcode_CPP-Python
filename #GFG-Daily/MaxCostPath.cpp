// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

// Date-> 02/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool isValid(int X, int Y, int n){
	    if(X>=0 && X<n && Y>=0 && Y<n){
	        return true;
	    }
	    return false;
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});
        
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            int cost = front.first;
            int x    = front.second.first;
            int y    = front.second.second;
            
            if(x==n-1 && y==n-1){
                return dist[n-1][n-1];
            }
            
            for(int i=0; i<4; i++){
                int newX = x + dir[i].first;
                int newY = y + dir[i].second;
                
                if(isValid(newX, newY, n)){
                    if(cost + grid[newX][newY] < dist[newX][newY]){
                        dist[newX][newY] = cost + grid[newX][newY];
                        pq.push({dist[newX][newY], {newX,newY}});
                    }
                }
            }
        }
        
        return -1;
    }
};