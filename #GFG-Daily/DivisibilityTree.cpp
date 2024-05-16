// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/divisibility-tree1902/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int components  = 0 ; 

    int  dfs( int src, vector<bool>&visited, vector< int> graph[]  )
    {
         visited[ src] = true;
         int count = 1 ;
         for ( auto adj  : graph [ src ] )
         {
            if ( visited[ adj]==  true )
                continue;
            int res = dfs( adj , visited, graph  );
            // cout << src << " -> " << res << endl;
            if( res %2 == 0 )
            {
                components ++;
            }
            else 
            {
                count += res ;
            }
         }
         return count;
    }
    
public:
    
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        
        vector< int > graph[ n +1 ];
        for ( auto it: edges )
        {
            graph[it[0]].push_back( it[1]);
            graph[it[1]].push_back ( it[0]);
        }
        vector< bool>visited( n + 1 , false ) ;
        dfs ( 1 , visited, graph );
        return components;
    }
};