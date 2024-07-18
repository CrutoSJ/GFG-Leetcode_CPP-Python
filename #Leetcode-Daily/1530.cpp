// #Question:-

// Link-> https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18

// Date-> 18/07/24

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
private:
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>> & adj,
                    unordered_set<TreeNode*> &st){
        if(root == NULL){
            return ;
        }

        if(root->left == NULL && root->right == NULL){
            st.insert(root);
        }

        if( prev != NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }


public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>>adj;
        unordered_set<TreeNode*>st;

        makeGraph(root, NULL, adj, st);

        int count = 0;

        for(auto &leaf : st){
            queue<TreeNode*>q;
            q.push(leaf);
            unordered_set<TreeNode*>visited;
            visited.insert(leaf);

            for(int level=0; level<=distance; level++){
                int size = q.size();
                while(size--){
                    TreeNode* front = q.front();
                    q.pop();

                    if(front != leaf && st.count(front)){
                        count++;
                    }

                    for(auto &ngbr : adj[front]){
                        if(!visited.count(ngbr)){
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};