#question:-

# You are given the heads of two sorted linked lists list1 and list2.
# Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
# Return the head of the merged linked list.

# Solution:-

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:      
        dummy = ListNode(0)
        tail = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        if list1:
            tail.next = list1
        if list2:
            tail.next = list2

        return dummy.next

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    list1 = input("Enter values for first linked list (separated by spaces): ").split()
    list1 = [int(val) for val in list1]
    list1 = [ListNode(val) for val in list1]

    list2 = input("Enter values for second linked list (separated by spaces): ").split()
    list2 = [int(val) for val in list2]
    list2 = [ListNode(val) for val in list2]

    for i in range(len(list1)-1):
        list1[i].next = list1[i+1]

    for i in range(len(list2)-1):
        list2[i].next = list2[i+1]

    merged_list = Solution().mergeTwoLists(list1[0], list2[0])

    while merged_list:
        print(merged_list.val, end=' ')
        merged_list = merged_list.next
        
