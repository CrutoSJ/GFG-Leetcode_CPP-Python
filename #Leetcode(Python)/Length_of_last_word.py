# Question:-

# Given a string s consisting of words and spaces, return the length of the last word in the string.
# A word is a maximal substring consisting of non-space characters only.

# Solution:-

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        arr = s.split()
        return len(arr[-1])
    
t = int(input("Enter no. of test cases: "))
for i in range(t):
    s = str(input("Enter the sentence: "))

    solution = Solution()
    result = solution.lengthOfLastWord(s)
    print(result)