// #Question:-

// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

// Return the decimal value of the number in the linked list.

// The most significant bit is at the head of the linked list.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            ans *= 2;
            ans += (temp->val);
            temp = temp->next;
        }
        return ans;
    }
};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    Solution sol;
    while (t--) {
        int n;
        cout << "Enter the number of elements in the linked list: ";
        cin >> n;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        cout << "Enter the elements (0 or 1) in the linked list: ";
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            ListNode* newNode = new ListNode(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        int decimalValue = sol.getDecimalValue(head);
        cout << "Decimal value: " << decimalValue << endl;

        // Free the memory to avoid memory leaks (optional).
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
