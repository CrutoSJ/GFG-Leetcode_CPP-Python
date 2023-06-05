// Question:-

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's 
// nodes (i.e., only nodes themselves may be changed.)

// Solution:- 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* p = head;
    ListNode* q = head->next;
    while (true) {
        swap(p->val, q->val);
        if (!(q->next && q->next->next))
            break;
        p = p->next->next;
        q = q->next->next;
    }
    return head;
}

ListNode* createLinkedList() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        return nullptr;
    }
    
    cout << "Enter the elements: ";
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    
    return head;
}

void displayLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        ListNode* head = createLinkedList();
        ListNode* result = swapPairs(head);
        displayLinkedList(result);

        ListNode* current = result;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
        
        return 0;
}
