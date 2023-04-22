# QUESTION:-

# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.

# Solution:-

def twoSum(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    nums = list(map(int, input("Enter the list of integers separated by space: ").split()))
    target = int(input("Enter the target value: "))

    result = twoSum(nums, target)
    print(result)

