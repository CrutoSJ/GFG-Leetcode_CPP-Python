# Question:-

# You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
# Increment the large integer by one and return the resulting array of digits.

# Solution:-
class Solution:
    def plusOne(self, digits):
        n = len(digits)
        carry = 1
        for i in range(n-1, -1, -1):
            digits[i] += carry
            if digits[i] < 10:
                return digits
            else:
                digits[i] = 0
                carry = 1
        if carry == 1:
            digits.insert(0, 1)
        return digits

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    digits = list(map(int, input().split()))
    
    solution = Solution()
    result = solution.plusOne(digits)

    print(result)





