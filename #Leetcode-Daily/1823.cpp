// #Question:-

// Link-> https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Date-> 08/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(deque<int>& ans, int k){
        if(ans.size()==1){
            return ans.front();
        }
        for(int i=1; i<k; i++){
            ans.push_back(ans.front());
            ans.pop_front();
        }
        ans.pop_front();        
        return solve(ans, k);
    }    
public:
    int findTheWinner(int n, int k) {
        deque<int>ans;
        for(int i=1; i<=n; i++){
            ans.push_back(i);
        }
        return solve(ans, k);
    }
};