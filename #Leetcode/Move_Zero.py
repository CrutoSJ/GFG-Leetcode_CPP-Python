# Question:-

# Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
# Note that you must do this in-place without making a copy of the array.

# Solution:-

from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero_index = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[zero_index], nums[i] = nums[i], nums[zero_index]
                zero_index += 1

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    nums = list(map(int, input("Enter the array elements: ").split()))

    sol = Solution()
    sol.moveZeroes(nums)

    print("Modified array:", nums)
