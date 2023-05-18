# Question:-

# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".

# Solution:-

from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        prefix = strs[0]

        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return "none"

        return prefix
    
t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    strs = input("Enter a list of strings (comma-separated): ").split(",")

    solution = Solution()
    result = solution.longestCommonPrefix(strs)
    print(result)