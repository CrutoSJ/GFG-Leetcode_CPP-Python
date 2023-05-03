# Question:-

# Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

# Solution:-

from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        a = 0
        for i in range (len(nums)):
            if nums[i] == a:
                a += 1
            else :
                return (a)
        return a
    
t = int(input("Enter no. of test cases: "))
for i in range (0,t):

    nums = list(map(int, input("Enter the elements of nums, separated by spaces: ").split()))

    solution = Solution()
    result = solution.missingNumber(nums)
    print(result)