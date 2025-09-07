// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

// Date-> 19/02/25 && 07/09/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *sorted(Node *head1, Node *head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;

        if (head1->data < head2->data)
        {
            head1->next = sorted(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = sorted(head1, head2->next);
            return head2;
        }
    }

    Node *mergeKLists(vector<Node *> &arr)
    {
        if (arr.empty())
            return NULL;

        Node *res = NULL;
        for (Node *temp : arr)
        {
            res = sorted(res, temp);
        }
        return res;
    }
};
