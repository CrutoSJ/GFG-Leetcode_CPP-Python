# Question:-
# Given two binary strings a and b, return their sum as a binary string.

# Example 1:
# Input: a = "11", b = "1"
# Output: "100"

# Solution:-

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        s = []
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        
        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1
            s.append(str(carry % 2))
            carry //=2
            
        return ''.join(reversed(s))
    
t = int(input("Enter no. of test cases: "))
for i in range(t):

    a = str(input("Enter A: "))
    b = str(input("Enter B: "))

    solution = Solution()
    result = solution.addBinary(a,b)
    print(result)