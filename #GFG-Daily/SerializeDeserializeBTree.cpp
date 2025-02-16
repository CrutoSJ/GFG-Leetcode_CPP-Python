// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

// Date-> 16/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of the tree.
    vector<int> serialize(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        vector<int> v;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            if (it != nullptr)
                v.push_back(it->data);
            else
                v.push_back(-1);

            if (it != nullptr)
            {
                q.push(it->left);
                q.push(it->right);
            }
        }

        return v;
    }

    // Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int>& A)
    {
        queue<Node*> q;
        Node* root = new Node(A[0]);
        int i = 1;
        int n = static_cast<int>(A.size());
        q.push(root);

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            if (i < n)
            {
                Node* leftChild = nullptr;
                if (A[i] != -1)
                    leftChild = new Node(A[i]);
                i++;
                it->left = leftChild;
                if (leftChild != nullptr)
                    q.push(leftChild);
            }
            else
            {
                it->left = nullptr;
            }

            if (i < n)
            {
                Node* rightChild = nullptr;
                if (A[i] != -1)
                    rightChild = new Node(A[i]);
                i++;
                it->right = rightChild;
                if (rightChild != nullptr)
                    q.push(rightChild);
            }
            else
            {
                it->right = nullptr;
            }
        }

        return root;
    }
};