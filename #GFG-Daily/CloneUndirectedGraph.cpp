// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/clone-graph/1

// Date-> 13/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    public:
      Node* cloneGraph(Node* node) {
          if (node == nullptr) return nullptr;
  
          unordered_map<Node*, Node*> mp;
          Node* newNode = new Node(node->val);
          mp[node] = newNode;
  
          queue<Node*> q;
          q.push(node);
  
          while (!q.empty()) {
              Node* cur = q.front();
              q.pop();
  
              for (Node* neighbor : cur->neighbors) {
                  if (mp.find(neighbor) == mp.end()) {
                      mp[neighbor] = new Node(neighbor->val);
                      q.push(neighbor);
                  }
                  mp[cur]->neighbors.push_back(mp[neighbor]);
              }
          }
  
          return newNode;
          
      }
  };