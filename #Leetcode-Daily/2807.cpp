// #Question:-

// Link-> https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10

// Date-> 10/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    int findGCD(int num1, int num2){
        for(int i=min(num1,num2); i>=1; i--){
            if(num1%i == 0 && num2%i == 0){
                return i;
            }
        }
        return 1;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        ListNode* prvs = NULL;

        while(temp->next != NULL){
            prvs = temp;
            temp = temp->next;

            int gcd = findGCD(prvs->val, temp->val);

            ListNode* node = new ListNode(gcd);
            prvs->next = node;
            node->next = temp;
        }

        return head; 
    }
};