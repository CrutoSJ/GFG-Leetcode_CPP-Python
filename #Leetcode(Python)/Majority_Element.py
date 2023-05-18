# Question:-

# Given an array nums of size n, return the majority element.
# The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

# Solution:-

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = {}
        for num in nums:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1
        majority_count = max(count.values())
        for num, freq in count.items():
            if freq == majority_count:
                return num
            

t = int(input("Enter no. of test cases: "))
for i in range (0,t):

    nums = list(map(int, input("Enter the elements of nums, separated by spaces: ").split()))
    
    solution = Solution()
    result = solution.majorityElement(nums)
    print(result)