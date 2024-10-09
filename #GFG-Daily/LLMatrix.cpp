// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/linked-list-matrix/1

// Date-> 09/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};

class Solution {
  public:
    void insertAtTail(Node* &head, Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = head;
        } else{
            tail->right = temp;
            tail = temp;
        }
    }
    
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<Node*> rowHead(n, NULL);
        vector<Node*> rowTail(n, NULL);

        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                insertAtTail(rowHead[i], rowTail[i], mat[i][j]);
            }
        }
        
        for(int i=0; i<n-1; i++){
            Node* currRow = rowHead[i];
            Node* nextRow = rowHead[i+1];
            
            while(currRow && nextRow){
                currRow->down = nextRow;
                
                currRow = currRow->right;
                nextRow = nextRow->right;
            }
        }
        
        return rowHead[0];
    }
};