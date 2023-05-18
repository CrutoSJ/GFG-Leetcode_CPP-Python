# Question:-

# Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

# Solution:-

from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        num_dict = {}
        for i in range(len(nums)):
            if nums[i] in num_dict and i - num_dict[nums[i]] <= k:
                return True
            num_dict[nums[i]] = i
        return False
    
t = int(input("Enter no. of test cases: "))
for i in range (0,t):

    nums = input("Enter comma-separated integers: ")
    nums = [int(x) for x in nums.split(",")]

    k = int(input("Enter the value of K = "))

    s = Solution()
    result = s.containsNearbyDuplicate(nums,k)
    print("Result:", result)