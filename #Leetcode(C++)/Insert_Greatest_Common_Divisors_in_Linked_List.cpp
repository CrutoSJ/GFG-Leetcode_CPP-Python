// #Question:-

// Given the head of a linked list head, in which each node contains an integer value.

// Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

// Return the linked list after insertion.

// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

// Example:- 

// Input: head = [18,6,10,3]
// Output: [18,6,6,2,10,1,3]
// Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
// - We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
// - We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
// - We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
// There are no more adjacent nodes, so we return the linked list.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int gcd(int num1, int num2) {
        for (int i = min(num1, num2); i >= 1; i--) {
            if (num1 % i == 0 && num2 % i == 0) {
                return i;
            }
        }
        return 1;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return head;
        }

        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            int num1 = temp->val;
            int num2 = temp->next->val;

            int num = gcd(num1, num2);

            ListNode* newNode = new ListNode(num);

            newNode->next = temp->next;
            temp->next = newNode;

            temp = newNode->next;
        }

        return head;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    
    while (t--) {
        int n;
        cout << "Enter the number of elements in the linked list: ";
        cin >> n;
        
        cout << "Enter the elements of the linked list: ";
        ListNode* head = NULL;
        ListNode* current = NULL;
        
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            ListNode* newNode = new ListNode(num);
            
            if (head == NULL) {
                head = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }
        
        Solution solution;
        ListNode* newHead = solution.insertGreatestCommonDivisors(head);
        
        cout << "Linked list after insertion of greatest common divisors: ";
        current = newHead;
        while (current != NULL) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    return 0;
}
