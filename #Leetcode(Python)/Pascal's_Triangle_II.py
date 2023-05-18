# Question:-

# Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
# In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

# Example 1:
# Input: rowIndex = 3
# Output: [1,3,3,1]

# Solution:-

from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [1]
        for i in range(1, rowIndex + 1):
            next_row = [1]
            for j in range(1, i):
                next_row.append(row[j - 1] + row[j])
            next_row.append(1)
            row = next_row
        return row

t = int(input("Enter the no. of test cases: "))
for i in range(t):
    rowIndex = int(input("enter value: "))

    solution = Solution()
    result = solution.getRow(rowIndex)
    print(result)
