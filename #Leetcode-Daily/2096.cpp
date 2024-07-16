// #Question:-

// Link-> https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16

// Date-> 16/07/24

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
    TreeNode* findLCA(TreeNode* root, int start, int end){
        if(root == NULL){
            return NULL;
        }

        if(root->val == start || root->val == end){
            return root;
        }

        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);

        if(left != NULL && right != NULL){
            return root;
        } else if(left != NULL && right == NULL){
            return left;
        } else if(left == NULL && right != NULL){
            return right;
        } else{
            return NULL;
        }
    }

    bool findPath(TreeNode* LCA, int target, string &ans){//finding the LCA and then the path, hence takes O(n)+O(n)+O(n)
        if(LCA == NULL){
            return false;
        }
        if(LCA->val == target){
            return true;
        }
        ans.push_back('L');
        if(findPath(LCA->left, target, ans)){
            return true;
        }
        ans.pop_back();
        ans.push_back('R');
        if(findPath(LCA->right, target, ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue); // O(n);

        string LToS = "";
        string LToD = "";

        findPath(LCA, startValue, LToS); // O(n);
        findPath(LCA, destValue, LToD);

        string ans="";

        for(int i=0; i<LToS.size(); i++){ // O(n);
            ans.push_back('U');
        }
        ans += LToD;
        return ans;
    }

    string getDirections2(TreeNode* root, int startValue, int destValue) {//Optimized i.e no need to calculate the LCA, directly finding paths & performing operations on it;

        string RToS = "";
        string RToD = "";

        findPath(root, startValue, RToS);// O(n);
        findPath(root, destValue, RToD);

        int l=0;
        while(l<RToS.size() && l<RToD.size() && RToS[l] == RToD[l]){
            l++;
        }

        string ans = "";

        for(int i=0; i<RToS.size()-l; i++){// O(n);
            ans.push_back('U');
        }

        for(int i=l; i<RToD.size(); i++){
            ans.push_back(RToD[i]);
        }
        return ans; // Hence Total TC - O(n) + O(n);
    }
};