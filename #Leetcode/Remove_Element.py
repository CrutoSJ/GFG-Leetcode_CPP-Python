# #question:-

# Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
# Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
# Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
# Return k.

# Answer:-
from typing import List
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    nums = input("Enter the array of integers, separated by spaces: ").split()
    nums = [int(num) for num in nums]
    val = int(input("Enter the value to remove: "))

    solution = Solution()
    result = solution.removeElement(nums, val)

    print(nums[:result]) 
    print(result)
