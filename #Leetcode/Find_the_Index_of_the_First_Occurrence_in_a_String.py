# Question:-

# Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

# Solution:-

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        if needle in haystack:
            return haystack.index(needle)
        else:
            return -1

t=int(input("enter the number of test cases: "))
for i in range (t):
    haystack = str(input("enter first string: "))
    needle = str(input("enter second string: "))

    solution = Solution()
    result = solution.strStr(haystack,needle)
    print(result)