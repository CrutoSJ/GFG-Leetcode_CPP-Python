# Question:-

# You are climbing a staircase. It takes n steps to reach the top.
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

# Solution:-

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1

        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1

        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]
    
t = int(input('Enter no. of test cases: '))
for i in range(t):
    n = int(input("Enter the value of n: "))

    solution = Solution()
    result = solution.climbStairs(n)
    print(result)