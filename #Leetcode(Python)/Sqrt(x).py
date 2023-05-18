# Question:-

# Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
# You must not use any built-in exponent function or operator.
# For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

# Solution:-

import math
class Solution:
    def mySqrt(self, x: int) -> int:
        n=x
        if x<2:
            return x
        for i in range(int(math.log(n,2))+1):
            n=(n+(x/n))/2
        return int(n)
        
t=int(input("Enter no. of test cases: "))
for i in range (t):
    x = int(input("Enter Number: "))

    solution = Solution()
    result = solution.mySqrt(x)
    print(result)