// #Question:-

// Link-> https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15

// Date-> 15/07/24

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>nodes;
        unordered_set<int>childs;

        for(auto & it: descriptions){
            int parent = it[0];
            int child  = it[1];
            int isLeft = it[2];

            if(nodes.find(parent) == nodes.end()){
                nodes[parent] = new TreeNode(parent);
            }

            if(nodes.find(child) == nodes.end()){
                nodes[child] = new TreeNode(child);
            }

            if(isLeft){
                nodes[parent]->left = nodes[child];
            } else{
                nodes[parent]->right = nodes[child];
            }

            childs.insert(child);
        }

        //finding the root;
        for(auto &it : descriptions){
            int parent = it[0];
            if(childs.find(parent) == childs.end()){
                return nodes[parent];
            }
        }

        return NULL;
    }
};