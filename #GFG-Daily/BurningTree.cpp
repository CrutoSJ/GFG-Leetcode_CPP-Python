// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/burning-tree/1

// Date-> 20/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* childToParent(Node* root, map<Node*, Node*> &CPMapping, int target){
        if(root == NULL){
            return NULL;
        }
        
        queue<Node*>q;
        q.push(root);
        CPMapping[root] = NULL;
        Node* ans = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                ans = front;
            }
            
            if(front->left){
                q.push(front->left);
                CPMapping[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                CPMapping[front->right] = front;
            }
            
        }
        return ans;
    }
    
    int BurnTree(Node* ans, map<Node*, Node*> CPMapping){
        if(ans == NULL){
            return NULL;
        }
        
        queue<Node*>q;
        q.push(ans);
        map<Node*, bool>visited;
        visited[ans] = 1;
        int cnt = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool isAdded = false;
            
            for(int i=0; i<size; i++){
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left] = 1;
                    isAdded = true;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right] = 1;
                    isAdded = true;
                }
                if(CPMapping[front] && !visited[CPMapping[front]]){
                    q.push(CPMapping[front]);
                    visited[CPMapping[front]] = 1;
                    isAdded = true;
                }
            }
            
            if(isAdded){
                cnt++;
            }
        }
        
        return cnt;
    }
    
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*>CPMapping;
        Node* ans = childToParent(root, CPMapping, target);
        int timeReq = BurnTree(ans, CPMapping);
        return timeReq;
    }
};