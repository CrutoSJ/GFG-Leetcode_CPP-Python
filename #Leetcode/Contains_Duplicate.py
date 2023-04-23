# Question:-

# Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

# Solution:-

from typing import List
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        length = len(nums)
        if length < 2:
            return False
        nums.sort()
        for i in range(length-1):
            if nums[i] == nums[i+1]:
                return True
        return False

t = int(input("Enter no. of test cases: "))
for i in range (0,t):       
            nums = input("Enter comma-separated integers: ")
            nums = [int(x) for x in nums.split(",")]

            s = Solution()

            result = s.containsDuplicate(nums)

            print("Result:", result)