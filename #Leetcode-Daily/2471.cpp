// #Question:-

// Link-> https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/?envType=daily-question&envId=2024-12-23

// Date-> 23/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(vector<int> &vec){
        int n = vec.size();
        int swaps=0;

        vector<int> vecS(vec.begin(), vec.end());
        sort(vecS.begin(), vecS.end());
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[vec[i]] = i;
        }

        for(int i=0; i<n; i++){
            if(vec[i] != vecS[i]){
                mp[vec[i]] = mp[vecS[i]];
                swap(vec[i], vec[mp[vecS[i]]]);
                swaps++;
            }
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int res=0;

        while(!q.empty()){
            int n=q.size();
            vector<int> lvlNodes;
            
            while(n--){
                TreeNode* top = q.front();
                q.pop();
                lvlNodes.push_back(top->val);

                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            res += solve(lvlNodes);
        }
        return res;
    }
};