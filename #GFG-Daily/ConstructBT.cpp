// #Question:-

// #Link-> https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:

    Node *solve(int in[], int post[], int is, int ie, int ps, int pe, map<int,int> &mp)
    {
        if(ie < is || pe < ps)
            return NULL;
        int inroot = mp[post[pe]];
        int count  = inroot - is;
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = post[pe];
        new_node->left =  solve(in,post,is,inroot-1,ps,ps+count-1,mp);
        new_node->right = solve(in,post,inroot+1,ie,ps+count,pe-1,mp);
        return new_node;
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) 
    {
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
        return solve(in,post,0,n-1,0,n-1,mp);
    }
};