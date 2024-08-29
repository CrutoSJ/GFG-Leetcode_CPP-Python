// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-length-of-loop/1

// Date-> 29/08/24

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int findNodes(Node *fast) {
        int cnt = 1;
        Node* temp = fast;
        while(temp->next != fast){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    int countNodesinLoop(Node *head) {
        if(head == NULL) return 0;
        Node* fast = head;
        Node* slow = head;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return findNodes(slow);
            }
        }
        return 0;
    }
};