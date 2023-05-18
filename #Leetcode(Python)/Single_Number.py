# Question:-

# Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
# You must implement a solution with a linear runtime complexity and use only constant extra space.

# Solution:-

def singleNumber(nums):
    result = 0
    for num in nums:
        result ^= num
    return result

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    input_str = input("Enter the array of integers: ")
    nums_str = input_str.split()
    nums = [int(num) for num in nums_str]

    single = singleNumber(nums)
    print(single)
