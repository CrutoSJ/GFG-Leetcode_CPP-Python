// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/k-sum-paths/1

// Date-> 10/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
      int sumK(Node *root, int k) {
          // code here
          unordered_map<int,int> ump;
          ump[0]=1;
          solve(root, k, ump, 0);
          return total;
      }
      private:
          int total = 0;
          const int mod=1e9+7;
          void solve(Node* node, int k, unordered_map<int,int> &ump, int sum){
              if(node==nullptr) return;
              sum+=node->data;
              if(ump.find(sum-k)!=ump.end()) total=(total+ump[sum-k])%mod;
              ump[sum]++;
              solve(node->left, k, ump, sum);
              solve(node->right, k, ump, sum);
              ump[sum]--;
              if(ump[sum]==0) ump.erase(sum);
          }
  };