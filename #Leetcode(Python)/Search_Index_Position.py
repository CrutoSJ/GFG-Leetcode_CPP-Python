# Question:-

# Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
# You must write an algorithm with O(log n) runtime complexity.

# Solution:-
from typing import List
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return left
    
t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    nums = input("Enter the array of integers, separated by spaces: ").split()
    nums = [int(num) for num in nums]
    target = int(input("Enter target value: "))

    solution = Solution()
    result = solution.searchInsert(nums, target)

    print(result)