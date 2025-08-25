// #Question:-

// Link-> https://leetcode.com/problems/diagonal-traverse/?envType=daily-question&envId=2025-08-25

// Date-> 25/08/25

// #Solution:-

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>> mp;
        vector<int> res;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool dir = true;

        for(auto &it : mp){
            if(dir){
                reverse(it.second.begin(), it.second.end());
            }
            
            for(int &num : it.second){
                res.push_back(num);
            }

            dir = !dir;
        }

        return res;
    }
};
