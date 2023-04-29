from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        mid = len(nums) // 2
        root = TreeNode(nums[mid])

        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:])

        return root


n = int(input("Enter the number of elements: "))
nums = list(map(int, input("Enter the elements (sorted in ascending order): ").split()))

sol = Solution()
root = sol.sortedArrayToBST(nums)

def inorder_traversal(node):
    if node:
        inorder_traversal(node.left)
        print(node.val, end=" ")
        inorder_traversal(node.right)


print("Inorder traversal of the binary search tree:")
inorder_traversal(root)
