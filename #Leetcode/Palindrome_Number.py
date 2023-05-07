# Question:-

# Given an integer x, return true if x is a palindrome, and false otherwise.

# Solution:-

class Solution:
    def isPalindrome(self, x: int) -> bool:
        string_x = str(x)
        rev_string_x = string_x[::-1]
        if (string_x == rev_string_x):
            return True
        else:
            return False
            
        
t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    x = int(input("Enter the number: "))

    solution = Solution()
    result = solution.isPalindrome(x)
    print(result)