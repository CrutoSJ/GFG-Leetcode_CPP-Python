// #Question:-

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start + 1 == end) {
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;
    }

};

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    Solution sol;

    while (t--) {
        int k;
        cout << "Enter the number of linked-lists (k): ";
        cin >> k;

        vector<ListNode*> lists(k, nullptr);

        for (int i = 0; i < k; ++i) {
            int n;
            cout << "Enter the number of elements for linked-list " << i + 1 << ": ";
            cin >> n;

            ListNode* head = nullptr;
            ListNode* curr = nullptr;

            for (int j = 0; j < n; ++j) {
                int val;
                cout << "Enter value for element " << j + 1 << ": ";
                cin >> val;

                ListNode* node = new ListNode(val);
                if (!head) {
                    head = node;
                    curr = node;
                } else {
                    curr->next = node;
                    curr = curr->next;
                }
            }

            lists[i] = head;
        }

        ListNode* mergedList = sol.mergeKLists(lists);

        cout << "Merged linked-list: ";
        ListNode* curr = mergedList;
        while (curr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "null" << endl;

        while (mergedList) {
            ListNode* temp = mergedList;
            mergedList = mergedList->next;
            delete temp;
        }
    }

    return 0;
}
