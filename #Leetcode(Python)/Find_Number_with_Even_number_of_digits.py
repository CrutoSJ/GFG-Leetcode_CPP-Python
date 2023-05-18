# Question:-

# Given an array nums of integers, return how many of them contain an even number of digits.

# Solution:-

from typing import List

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        a = 0
    
        for i in nums:        
            if (len(str(i)))% 2 == 0:
                a = a+1
        return (a)

t = int(input("Enter no. of test cases: "))
for i in range (t):
    nums = list(map(int, input("elements of array:-").strip().split()))

    solution = Solution()
    result = solution.findNumbers(nums)
    print(result)